// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// 1. Can both the child and parent access the file descriptor returned by `fopen()`?
// Yes, both child and parent had access since you can write to fp.

// 2. What happens when they are written to the file concurrently?
// They both get saved.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    fp = fopen("text.txt", "w");
    printf("===Opening the file in write mode===\n");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        fprintf(fp, "%s \n", "child");
        printf("===Finished writing to file (Child)===\n");
    }
    else
    {
        fprintf(fp, "%s \n", "parent");
        printf("===Finished writing to file (Parent)===\n");
    }

    printf("===Closing the file===\n");
    fclose(fp);
    return 0;
}
