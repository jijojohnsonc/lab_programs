#include<stdio.h>
#include<stdlib.h>

struct process
{
    int *max;
    int *allocation;
    int *need;
};
int n;
int *avail;
struct process *p;
int m;

void display()
{
    printf("\n PROCESS ID\t| MAX");
    for (int i = 0; i < n; i++)
        printf("\t");
    printf("| ALLOCATION");
    for (int i = 0; i < n - 1; i++)
        printf("\t");
    printf("| NEED\n\t\t");
    for (int i = 0; i < 3; i++)
    {
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%c\t", 'A' + j);
    }
    for (int i = 0; i < m; i++)
    {
        printf("\n P%d\t\t| ", i + 1);
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i].max[j]);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i].allocation[j]);
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i].need[j]);
    }
    printf("\n\nAVAILABLE : ");
    for (int j = 0; j < n; j++)
        printf("\t%d", avail[j]);
    printf("\n");
}

int safety()
{
    int complete_count = 0, completed[m];
    for (int i = 0; i < m; i++)
        completed[i] = 0;
    int current_avail[n];
    for (int j = 0; j < n; j++)
        current_avail[j] = avail[j];
    while (complete_count < m)
    {
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            if (completed[i])
                continue;
            int flag = 0;
            for (int j = 0; j < n; j++)
                if (p[i].need[j] > current_avail[j])
                {
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                for (int k = 0; k < n; k++)
                    current_avail[k] += p[i].allocation[k];
                count++;
                completed[i] = 1;
                printf("\nP%d completed\nAVAILABLE = ", i + 1);
                for (int k = 0; k < n; k++)
                    printf("\t%d", current_avail[k]);
                printf("\n");
            }
        }
        if (count == 0)
            break;
        complete_count += count;
    }
    if (complete_count < m)
        return 0;
    return 1;
}

int resource_request()
{
    int p_no;
    printf("\nEnter the PROCESS ID : P");
    scanf("%d", &p_no);
    p_no--;
    int request[n];
    printf("Enter the REQUEST : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
        if (request[i] > p[p_no].need[i] || request[i] > avail[i])
            return 0;
    }
    for (int j = 0; j < n; j++)
    {
        avail[j] -= request[j];
        p[p_no].allocation[j] += request[j];
        p[p_no].need[j] -= request[j];
    }
    display();
    int flag = safety();
    for (int j = 0; j < n; j++)
    {
        avail[j] += request[j];
        p[p_no].allocation[j] -= request[j];
        p[p_no].need[j] += request[j];
    }
    return flag;
}

void main()
{
    printf("Enter the number of resources : ");
    scanf("%d", &n);
    printf("Enter the number of processes : ");
    scanf("%d", &m);
    p = malloc(m * sizeof(*p));
    for (int i = 0; i < m; i++)
    {
        printf("\nP%d - \n", i + 1);
        p[i].max = malloc(n * sizeof(*p[i].max));
        printf("Enter MAX : ");
        for (int j = 0; j < n; j++)
            scanf("%d", &p[i].max[j]);
        p[i].allocation = malloc(n * sizeof(*p[i].allocation));
        p[i].need = malloc(n * sizeof(*p[i].allocation));
        printf("Enter ALLOCATION : ");
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &p[i].allocation[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }
    avail = malloc(n * sizeof(*avail));
    printf("\nEnter AVAILABLE : ");
    for (int j = 0; j < n; j++)
        scanf("%d", &avail[j]);
    display();
    while (1)
	{
		int opt;
		printf("\n1) Safety Algorithm\n");
		printf("2) Resource Request Algorithm\n");
		printf("3) Exit\n");
        printf("Enter your choice : ");	
		scanf("%d", &opt);
		if (opt == 1)
        {
            if (safety())
                printf("\nThe system is in safe state\n");
            else
                printf("\nDeadlock! The system is not in safe state\n");
        }
		else if (opt == 2)
        {
            if (resource_request())
                printf("\nThe system is in safe state, therefore, the request can be granted\n");
            else
                printf("\nDeadlock! The request cannot be granted\n");
        }
        else if (opt == 3)
			break;
		else
			printf("Invalid entry");
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
        {
            if (safety())
                printf("\nThe system is in safe state\n");
            else
                printf("\nDeadlock! The system is not in safe state\n");
        }
		else if (opt == 2)
        {
            if (resource_request())
                printf("\nThe system is in safe state, therefore, the request can be granted\n");
            else
                printf("\nDeadlock! The request cannot be granted\n");
        }
        else if (opt == 3)
			break;
		else
			printf("Invalid entry");
	}
}