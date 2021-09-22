#include <stdio.h>

void fcfs(int page[], int n, int frame[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        frame[i] = page[i];
    }
    i = 0;
    int j, no_page_faults;
    for (j = size; j < n; j++)
}

void main()
{
    int size;
    printf("Enter the frame size : ");
    scanf("%d", &size);
    int frame[size];
    int n;
    printf("Enter length of page reference string : ");
    scanf("%d", &n);
    int page[n];
    printf("Enter the string : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    while (1)
	{
		int opt;
		printf("\n1) FIFO\n");
		printf("2) LRU\n");
		printf("3) LFU\n");
        printf("4) Exit\n");
        printf("Enter your choice : ");	
		scanf("%d", &opt);
		if (opt == 1)
        {

        }
		else if (opt == 2)
        {

        }
        else if (opt == 3)
			break;
		else
			printf("Invalid entry");
	}
}