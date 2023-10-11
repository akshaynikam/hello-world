/*
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ./a.out
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ cd data/
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue/data$ ls -ltr
 * total 8
 * -rw-r--r-- 1 aknikam aknikam 16394 May 24 11:33 file.hole
 * -rw-rw-rw- 1 aknikam aknikam     0 Jun 22 14:19 foo
 * -rw------- 1 aknikam aknikam     0 Jun 22 14:19 bar
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue/data$
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
    umask(0);
    if (creat("data/foo", RWRWRW) < 0) {
        fprintf(stderr, "creat error for foo");
        return -1;
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("data/bar", RWRWRW) < 0) {
        fprintf(stderr, "creat error for bar");
        return -1;
    }

    return 0;
}
