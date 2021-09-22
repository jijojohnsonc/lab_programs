#include <stdio.h>

int mutex = 1, full = 0, empty, x = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

void main()
{
	printf("Enter buffer size: ");
	scanf("%d", &empty);
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        if (n == 1)
        {
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full!!");
        }
        else if (n == 2)
        {
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty!!");
        }
        else if (n == 3)
            break;
        else
            printf("Invalid entry");
    }
}