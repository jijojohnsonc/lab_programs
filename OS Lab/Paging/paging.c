#include <stdio.h>

void fcfs(int page[], int n, int frame[], int size)
{
    int i;
    int first_in[size];
    for (i = 0; i < size; i++)
    {
        frame[i] = page[i];
        first_in[i] = frame[i];
        printf("Miss\n");
        for (x = 0; x <= i; x++)
            printf("%d\t", frame[x]);
        printf("\n");
    }
    int j, no_of_page_faults = i;
    for (j = size; j < n; j++)
    {
    	int flag = 0;
    	for (int k = 0; k < i; k++)
    	{
    		if (page[i] == frame[k])
    		{
    			flag = 1;
    			printf("Hit\n");
    		}
    		if (!flag)
    		{
    		no_of_page_faults++;
    			printf("Miss\n");
    			int l;
    			for (l = 0; l < k; l++)
    			{
    				if (frame[l] == first_in[0])
    				{
    					for (m = 1; m < size; m++)
    						first_in[m - 1] = first_in[m];
    					frame[l] = page[i];
    					first_in[size - 1] = page[i];
    					i = (i + 1) % size;
    				}	
    			}
    		}
    		for (x = 0; x < size; x++)
            		printf("%d\t", frame[x]);
    	}
    }
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
			fcfs(page, n, frame, size);
        		}
		else if (opt == 2)
        		{
;
        		}
        		else if (opt == 3)
			break;
		else
			printf("Invalid entry");
	}
}
