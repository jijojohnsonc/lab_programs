#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void fibonacci(long n)
{
    printf("Fibonacci sequence (child process) :\n");
    if (n < 1)
        return;
    long a = 0, b = 1;
    printf("%li  ", a);
    for (long i = 1; i < n; i++)
    {
        printf("%li  ", b);
        b = a + b;
        a = b - a;
    }
    printf("\n");
}

void prime_nos(long n)
{
    printf("Prime numbers (parent process) :\n");
    if (n < 1)
        return;
    long x = 2;
    long prime[n];
    prime[0] = x;
    printf("%li  ", x++);
    long i = 1;
    while (i < n)
    {
        long flag = 0;
        for (long j = 0; j < i; j++)
            if (x % prime[j] == 0)
                flag = 1;
        if (!flag)
        {
            printf("%li  ", prime[i] = x);
            i++;
        }
        x += 2;
    }
    printf("\n");
}

void main()
{
    long n;
    printf("Enter the value of n : ");
    scanf("%li", &n);

    if (fork() == 0) // child process
        fibonacci(n);
    else // parent process
    {
        wait(NULL);
        prime_nos(n);
    }
}