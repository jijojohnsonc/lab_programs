#include <stdio.h>

int search(int frame[], int size, int key)
{
    int i = 0, flag = 0;
    while (i < size)
    {
        if (key == frame[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    return flag;
}

void print_frame(int frame[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(frame[i] != -1)
		{
		    printf("%d ",frame[i]);
		}
		else
		{
		    break;
		}
	}
	printf("\n");
}

void fifo(int page[], int n, int frame[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		frame[i] = -1;
	int no_of_page_faults = 0;
	i = 0;
	for (int j = 0; j < n; j++)
	{
		if (!search(frame, size, page[j]))
		{
			frame[(i + size) % size] = page[j];
			no_of_page_faults++;
			print_frame(frame, size);
			i++;
		}
	}
	printf("No. of page faults = %d\n", no_of_page_faults);
}


void lru(int page[], int n, int frame[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		frame[i] = -1;
	int no_of_page_faults = 0;
	i = 0;
	int recent_index[size];
	for (i = 0; i < size; i++)
		recent_index[i] = -1;
	for (int j = 0; j < n; j++)
	{
		if (!search(frame, size, page[j]))
		{
			for (int k = 0; k < size; k++)
			{
				for (int l = 0; l < j; k++)
				{
					if (frame[k] == page[l])
						recent_index[k] = l;
				}
				int least = recent_index[0];
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
			fifo(page, n, frame, size);
        		}
		else if (opt == 2)
        		{
;
        		}
        		else if (opt == 4)
			break;
		else
			printf("Invalid entry");
	}
}
