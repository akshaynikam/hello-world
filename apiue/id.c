/*
 * When we execute a program file, the effective user ID of the process is usually the real user ID, and the effective group ID is usually the real group ID.
 * However, we can also set a special flag in the file’s mode word (st_mode) that says,
 * “When this file is executed, set the effective user ID of the process to be the owner of the file (st_uid).”
 * Similarly, we can set another bit in the file’s mode word that causes the effective group ID to be the group owner of the file (st_gid).
 * These two bits in the file’s mode word are called the set-user-ID bit and the set-group-ID bit.
 *
 * Set set-user-ID: chmod u+s <executable>
 * Set set-group-ID: chmod g+s <executable>
 *
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ./a.out
 * uid : 1000
 * gid : 1000
 * euid : 1000
 * egid : 1000
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ sudo ./a.out
 * uid : 0
 * gid : 0
 * euid : 0
 * egid : 0
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ chmod g+s a.out
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ./a.out
 * uid : 1000
 * gid : 1000
 * euid : 1000
 * egid : 1000
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ sudo ./a.out
 * uid : 0
 * gid : 0
 * euid : 0
 * egid : 1000
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ chmod u+s a.out
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ ./a.out
 * uid : 1000
 * gid : 1000
 * euid : 1000
 * egid : 1000
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$ sudo ./a.out
 * uid : 0
 * gid : 0
 * euid : 1000
 * egid : 1000
 * (base) aknikam@aknikam-ubuntu18:~/mango/hello-world/apiue$
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    printf("uid : %d\n", getuid());
    printf("gid : %d\n", getgid());
    printf("euid : %d\n", geteuid());
    printf("egid : %d\n", getegid());

    return 0;
}
