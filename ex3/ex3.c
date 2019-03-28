// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    if (fork() == 0) {
        printf("Hello, child process %d\n\n", (int) getpid());
    } else {
        // wait must have one argument, allows the parent to wait for the child process to finish before moving on with the parent
        wait(NULL);
        printf("Goodbye, parent process %d\n\n", (int) getpid());
    };
    
    return 0;
}
