#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    if (fork() == 0)
    {
        if (fork() == 0)
        {
            if (fork() == 0)
            {
                if (fork() == 0)
                    printf("(I) P#%d, forked by P#%d\n", getpid(), getppid());
                else
                {
                    wait(NULL);
                    printf("(H) P#%d, forked by P#%d\n", getpid(), getppid());
                }
            }
            else
            {
                wait(NULL);
                printf("(D) P#%d, forked by P#%d\n", getpid(), getppid());
            }
        }
        else if (fork() == 0)
            printf("(E) P#%d, forked by P#%d\n", getpid(), getppid());
        else if (fork() == 0)
            printf("(F) P#%d, forked by P#%d\n", getpid(), getppid());
        else
        {
            wait(NULL);
            printf("(B) P#%d, forked by P#%d\n", getpid(), getppid());
        }
    }
    else if (fork() == 0)
    {
        if (fork() == 0)
            printf("(G) P#%d, forked by P#%d\n", getpid(), getppid());
        else
        {
            wait(NULL);
            printf("(C) P#%d, forked by P#%d\n", getpid(), getppid());
        }
    }
    else
    {
        wait(NULL);
        printf("(A) P#%d\n", getpid());
    }
}