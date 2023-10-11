/*
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ls -l data/
 * total 8
 * -rw------- 1 aknikam aknikam     0 Jun 22 14:19 bar
 * -rw-r--r-- 1 aknikam aknikam 16394 May 24 11:33 file.hole
 * -rw-rw-rw- 1 aknikam aknikam     0 Jun 22 14:19 foo
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ./a.out 
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ls -l data/
 * total 8
 * -rw-r--r-- 1 aknikam aknikam     0 Jun 22 14:19 bar
 * -rw-r--r-- 1 aknikam aknikam 16394 May 24 11:33 file.hole
 * -rw-rwSrw- 1 aknikam aknikam     0 Jun 22 14:19 foo
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    struct stat statbuf;

    // turn on set-group-id and turn off group-execute
    if (stat("data/foo", &statbuf) < 0) {
        fprintf(stderr, "failed to execute stat on foo\n");
        return -1;
    }

    if (chmod("data/foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        fprintf(stderr, "failed to execute chmod on foo\n");
        return -1;
    }

    // set absolute mode to "rw-r--r--"
    if (chmod("data/bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        fprintf(stderr, "failed to execute chmod on bar\n");
        return -1;
    }
}