#include<stdio.h>

void allocation(int block[], int n, int process[], int m, int type)
{
    int allocated[n];
    for (int i = 0; i < n; i++)
        allocated[i] = -1;

    for (int i = 0; i < m; i++) // i -> process
    {
        int index = -1;
        for (int j = 0; j < n; j++) // j -> block
        {
            if (allocated[j] == -1 && block[j] >= process[i])
            {
                index = j;
                break;
            }
        }
        if (index == -1)
            printf("\nProcess %d cannot be allocated\n", i + 1);
        else
        {
            if (type == 1) // Worst Fit
            {
                for (int j = index + 1; j < n; j++)
                {
                    if (allocated[j] == -1 && block[j] > block[index])
                        index = j;
                }
            }
            else if (type == 2) // Best Fit
            {
                for (int j = index + 1; j < n; j++)
                {
                    if (allocated[j] == -1 && block[j] >= process[i] && block[j] < block[index])
                        index = j;
                }
            }
            allocated[index] = i;
            printf("\nProcess %d allocated to block %d\n", i + 1, index + 1);
            printf("Internal Fragmentation = %d KB\n", block[index] - process[i]);
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    int block[n];
    printf("Enter the size (in KB) of\n");
    for (int i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    int m;
    printf("\nEnter the number of processes: ");
    scanf("%d", &m);
    int process[m];
    printf("Enter the size (in KB) of\n");
    for (int i = 0; i < m; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
    }
    
    while (1)
	{
		int opt;
		printf("\n1) First Fit\n");
		printf("2) Worst Fit\n");
		printf("3) Best Fit\n");
        printf("4) Exit\n");
        printf("Enter your choice : ");	
		scanf("%d", &opt);
		if (opt == 1)
            allocation(block, n, process, m, 0);
		else if (opt == 2)
            allocation(block, n, process, m, 1);
        else if (opt == 3)
            allocation(block, n, process, m, 2);
        else if (opt == 4)
			break;
		else
			printf("Invalid entry");
	}
}