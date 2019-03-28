// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x;
    x = 100;


    int child = fork();

    // if we change x here both will have the new value of x, if we change it in the child only the child will use the new value of x


    if (child == 0) {
        printf("%d child before the change %d\n\n", child, x);

        // change the value in the child
        x = x + 100;
        printf("%d child after the change %d\n\n", child, x);
    } else {
        printf("Parent here %d, x is %d\n\n", (int) getpid(), x );
    };

    return 0;
}
