// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


// The parent goes first at writing, then the child can now write in the file

int main(void)
{
    FILE *f;

    f = fopen("text.txt", "r+");

    int child = fork();

    if (child == 0) {
       fprintf(f, "Lets write into this file from the child\n\n");
    } else {
        fprintf(f, "the parent is writing in here\n\n");
    };

    fclose(f);

    return 0;
}
