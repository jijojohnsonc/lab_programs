#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("(1) P#%d\n", getpid());
    for (int i = 1; i < n; i++)
    {
        if (fork() == 0)
            printf("(%d) P#%d, child of P#%d\n", i + 1, getpid(), getppid());
        else if (fork() == 0)
            printf("(%d) P#%d, child of P#%d\n", i + 1, getpid(), getppid());
        else
        {
            wait(NULL);
            break;
        }
    }
}