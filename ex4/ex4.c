// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    if(fork() == 0) {
        printf("I'm a child!\n\n");
        char *args[] = {"./ex4demo", NULL};
        execl("/bin/ls", "ls", NULL);
        // 2nd call won't run
        execvp(args[0], args);
    } else {
        wait(NULL);
        printf("I'm a parent!\n\n");
    };

    return 0;
}


// Functions in the exec() family have different behaviours:

// l : arguments are passed as a list of strings to the main()
// v : arguments are passed as an array of strings to the main()
// p : path/s to search for the new running program
// e : the environment can be specified by the caller
// You can mix them, therefore you have:

// int execl(const char *path, const char *arg, ...);
// int execlp(const char *file, const char *arg, ...);
// int execle(const char *path, const char *arg, ..., char * const envp[]);
// int execv(const char *path, char *const argv[]);
// int execvp(const char *file, char *const argv[]);
// int execvpe(const char *file, char *const argv[], char *const envp[]);
// For all of them the initial argument is the name of a file that is to be executed.
