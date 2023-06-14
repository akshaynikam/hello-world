#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct page {
    char block[512];
    int next_block;
};

struct file_info {
    char name[10];
    int data;
    int next_inode;
};

struct metadata {
    size_t memory;
    int max_files;
    int data_block_size;
    int free_data;
    int free_inode;
    int inode_start;
};

#define INODE(vfs, node) ((struct file_info*)(vfs + sizeof(struct metadata) + sizeof(struct file_info) * node))
#define PAGE(vfs, data) ((struct page*) \
        (vfs + sizeof(struct metadata) + \
         sizeof(struct file_info) * ((struct metadata*)vfs)->max_files + \
         sizeof(struct page) * data))

void scan_vfs(void* vfs) {
    int free_inode = -1;
    int free_data = -1;
    struct metadata* metadata = (struct metadata*) vfs;
    if (vfs == NULL)
        return;

    printf("Total memory : %zu\n", metadata->memory);
    printf("Max files : %d\n", metadata->max_files);
    printf("Block size : %d\n", metadata->data_block_size);
    printf("First Inode : %d\n", metadata->inode_start);
    printf("Free Data : %d", metadata->free_data);
    free_data = metadata->free_data;
    while (free_data != -1) {
        free_data = PAGE(vfs, free_data)->next_block;
        printf(" -> %d", free_data);
    }

    printf("\n");

    printf("Free Inode : %d", metadata->free_inode);
    free_inode = metadata->free_inode;
    while (free_inode != -1) {
        free_inode = INODE(vfs, free_inode)->next_inode;
        printf(" -> %d", free_inode);
    }

    printf("\n");
}

void* init_vfs(size_t memory) {
    int i = 0;
    void* base_addr = NULL;
    void* addr_itr = NULL;
    void* start_data_addr = NULL;
    void* start_inode_addr = NULL;
    void* end_inode_addr = NULL;
    struct metadata* metadata = NULL;

    base_addr = malloc(memory);

    if (base_addr == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }

    metadata = (struct metadata*) base_addr;

    metadata->memory = memory;
    metadata->max_files = 5;
    metadata->data_block_size = sizeof(struct page);
    metadata->inode_start = -1;
    metadata->free_inode = 0;
    metadata->free_data = 0;

    start_inode_addr = INODE(base_addr, 0);
    end_inode_addr = PAGE(base_addr, 0);
    for (addr_itr = start_inode_addr;
         addr_itr < end_inode_addr - sizeof(struct file_info);
         addr_itr += sizeof(struct file_info)) {
        ((struct file_info*)addr_itr)->next_inode = ++i;
    }

    ((struct file_info*)addr_itr)->next_inode = -1;

    i = 1;
    start_data_addr = end_inode_addr;

    for (addr_itr = start_data_addr;
         addr_itr < base_addr + memory - sizeof(struct page);
         addr_itr += metadata->data_block_size) {
        ((struct page*)addr_itr)->next_block = i++;
    }

    ((struct page*)addr_itr)->next_block = -1;

    return base_addr;
}

void distroy_fs(void* vfs) {
    memset(vfs, 0, ((struct metadata*)vfs)->memory);
    free(vfs);
}

int get_free_inode(void* vfs) {
    struct metadata* metadata = (struct metadata*) vfs;
    int free_inode = metadata->free_inode;

    if (free_inode == -1) {
        fprintf(stderr, "Not enough memory\n");
        return free_inode;
    }

    metadata->free_inode = INODE(vfs, free_inode)->next_inode;
    INODE(vfs, free_inode)->next_inode = -1;

    return free_inode;
}

int get_free_blk(void* vfs) {
    struct metadata* metadata = (struct metadata*) vfs;
    int free_data = metadata->free_data;

    if (free_data == -1) {
        fprintf(stderr, "Not enough memory\n");
        return free_data;
    }

    metadata->free_data = PAGE(vfs, free_data)->next_block;
    PAGE(vfs, free_data)->next_block = -1;

    return free_data;
}

int create_file(void* vfs, char name[]) {
    struct metadata* metadata = (struct metadata*)vfs;
    int free_inode = -1;

    free_inode = get_free_inode(vfs);
    if (free_inode == -1)
        return -1;

    strncpy(INODE(vfs, free_inode)->name, name, 10);
    INODE(vfs, free_inode)->data = -1;
    INODE(vfs, free_inode)->next_inode = metadata->inode_start;
    metadata->inode_start = free_inode;

    return 0;
}

void free_blk(void* vfs, int inode) {
    int next_data = -1;
    int data = INODE(vfs, inode)->data;
    struct metadata* metadata = (struct metadata*) vfs;
    while (data != -1) {
        memset(PAGE(vfs, data)->block, 0, sizeof(PAGE(vfs, data)->block));
        next_data = PAGE(vfs, data)->next_block;
        
        // add block into free list
        PAGE(vfs, data)->next_block = metadata->free_data;
        metadata->free_data = data;
    
        data = next_data;
    }
}

void find_inode(void* vfs, char name[], int* prev_inode, int* inode) {
    *prev_inode = -1;
    while (*inode != -1) {
        if (0 == strcmp(INODE(vfs, *inode)->name, name)) {
            return;
        }

        *prev_inode = *inode;
        *inode = INODE(vfs, *inode)->next_inode;
    }
}

void write_data(void* vfs, char name[], char data[]) {
    struct metadata* metadata = (struct metadata*) vfs;
    int inode = metadata->inode_start;
    int prev_inode = -1;
    int blk = -1;
    int prev_blk = -1;
    int len_to_write = 0;
    int len = strlen(data);

    find_inode(vfs, name, &prev_inode, &inode);

    if (inode == -1) {
        fprintf(stderr, "%s does not exists\n", name);
        return;
    }

    free_blk(vfs, inode);

    while (len) {
        blk = get_free_blk(vfs);
        if (blk == -1) {
            fprintf(stderr, "Not enough space\n");
            return;
        }

        if (prev_blk == -1) {
            INODE(vfs, inode)->data = blk;
        } else {
            PAGE(vfs, prev_blk)->next_block = blk;
        }

        if (len <= sizeof(PAGE(vfs, blk)->block)) {
            len_to_write = len;
            len = 0;
        } else {
            len_to_write = sizeof(PAGE(vfs, blk)->block);
            len -= len_to_write;
        }

        memcpy(PAGE(vfs, blk)->block, data, len_to_write);
        data += len_to_write;
        prev_blk = blk;
    }
}

void delete_file(void* vfs, char* name) {
    int prev_inode = -1;
    struct metadata* metadata = (struct metadata*) vfs;
    int inode = metadata->inode_start;

    find_inode(vfs, name, &prev_inode, &inode);
    if (inode != -1) {
        if (prev_inode != -1) { // if being deleted inode is not at the start of the list
            INODE(vfs, prev_inode)->next_inode = INODE(vfs, inode)->next_inode;
        } else { // if being deleted inode is at the start of the list
            metadata->inode_start = INODE(vfs, inode)->next_inode;
        }

        // add inode into free list
        INODE(vfs, inode)->next_inode = metadata->free_inode;
        metadata->free_inode = inode;

        // free the data for this file
        free_blk(vfs, inode);

    }
}

void list_files(void* vfs) {
    struct metadata* metadata = (struct metadata*) vfs;
    void* addr_itr = NULL;
    int inode = metadata->inode_start;
    int data = -1;

    printf("===List of files ===\n");
    while (inode != -1) {
        addr_itr = vfs + sizeof(struct metadata) + sizeof(struct file_info) * inode;
        printf("%s : ", ((struct file_info*)addr_itr)->name);
        data = INODE(vfs, inode)->data;
        while (data != -1) {
            printf("%s ", PAGE(vfs, data)->block);
            data = PAGE(vfs, data)->next_block;
        }
        printf("\n");

        inode = ((struct file_info*)addr_itr)->next_inode;
    }
}

void backup(void* vfs, char file[]) {
    int fd = open(file, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        fprintf(stderr, "backup failed\n");
        return;
    }

    write(fd, vfs, ((struct metadata*)vfs)->memory);
    close(fd);
}

void* restore(char file[]) {
    int fd = open(file, O_RDONLY);
    size_t memory = 0;
    void* vfs = NULL;

    if (fd == -1) {
        fprintf(stderr, "restore failed\n");
        return vfs;
    }

    read(fd, &memory, sizeof(memory));

    vfs = malloc(memory);
    if (vfs == NULL) {
        fprintf(stderr, "failed to allocate memory\n");
    } else {
        lseek(fd, SEEK_SET, 0);
        read(fd, vfs, memory);
    }

    close(fd);
    return vfs;
}

void rename_file(void* vfs, char oldname[], char newname[]) {
    int inode = ((struct metadata*)vfs)->inode_start;
    int prev_inode = -1;

    find_inode(vfs, oldname, &prev_inode, &inode);

    if (inode == -1) {
        fprintf(stderr, "%s does not exists\n", oldname);
        return;
    }

    strncpy(INODE(vfs, inode)->name, newname, strlen(newname));
}

int main() {
    size_t memory = 1024 * 2; // 4MB
    void* vfs = init_vfs(memory);

    if (vfs == NULL) {
        return -1;
    }

    //scan_vfs(vfs);
    //list_files(vfs);

    //create_file(vfs, "f1");
    //create_file(vfs, "f2");
    //create_file(vfs, "f3");
    //create_file(vfs, "f4");
    //create_file(vfs, "f5");
    //delete_file(vfs, "f3");
    //create_file(vfs, "f7");

    //scan_vfs(vfs);
    //list_files(vfs);

    //delete_file(vfs, "f7");
    //delete_file(vfs, "f5");
    //delete_file(vfs, "f4");
    //delete_file(vfs, "f2");
    //delete_file(vfs, "f1");

    //scan_vfs(vfs);
    //list_files(vfs);

    create_file(vfs, "f1");
    create_file(vfs, "f2");
    create_file(vfs, "f3");
    create_file(vfs, "f4");
    create_file(vfs, "f5");
    delete_file(vfs, "f3");
    create_file(vfs, "f7");

    scan_vfs(vfs);
    list_files(vfs);

    write_data(vfs, "f4", "Akshay Nikam, f4");
    write_data(vfs, "f7", "This is just a testing.. The most common use of these system calls is to truncate a file.. The most common use of these system calls is to truncate a file.. The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file.. The most common use of these system calls is to truncate a file.. The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file... The most common use of these system calls is to truncate a file f7");
    scan_vfs(vfs);
    list_files(vfs);

    //rename_file(vfs, "f4", "fxxx");
    //list_files(vfs);

    //backup(vfs, "/tmp/fs.bkp");

    distroy_fs(vfs);
    vfs = NULL;

    //vfs = restore("/tmp/fs.bkp");
    //scan_vfs(vfs);
    //list_files(vfs);

    return 0;
}
