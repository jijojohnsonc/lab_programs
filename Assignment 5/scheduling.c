#include<stdio.h>

struct process
{
    int id;
    float bt;       // Burst Time
    float at;       // Arrival Time
    float tat;      // Turnaround Time
    float wt;       // Waiting Time
    float rt;       // Remaining Time
    float ct;       // Completion Time
    int priority;
};

void merge(struct process arr[], int p, int q, int r, int c)
{
    int n1 = q - p + 1, n2 = r - q;
    struct process L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + j + 1];
    int i = 0, j = 0;
    int k = p;
    while (i < n1 && j < n2)
    {
        int condition;
        if (c == 0)
            condition = (L[i].at <= R[j].at); // Sort by Arrival Time
        else if (c == 1)
            condition = (L[i].id <= R[j].id); // Sort by Process no.
        if (condition)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void sort(struct process arr[], int p, int r, int c) // Merge Sort
{
    if (p < r)
    {
        int q = (p + r) / 2;
        sort(arr, p, q, c);
        sort(arr, q + 1, r, c);
        merge(arr, p, q, r, c);
    }
}

void display_process(int n, struct process p[], int priority)
{
    if (priority)
    {
        printf("\nProcess\t| Burst Time\t| Arrival Time\t| Priority\n");
        for (int i = 0; i < n; i++)
            printf("P%d\t| %.2f\t\t| %.2f\t\t| %d\n", p[i].id, p[i].bt, p[i].at, p[i].priority);
    }
    else
    {
        printf("\nProcess\t| Burst Time\t| Arrival Time\n");
        for (int i = 0; i < n; i++)
            printf("P%d\t| %.2f\t\t| %.2f\n", p[i].id, p[i].bt, p[i].at);
    }
}

void turnaround_time(int n, struct process p[])
{
    printf("\nTurnaround Time:-\n");
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (p[i].tat = p[i].ct - p[i].at);
        printf("P%d: %.2f\n", p[i].id, p[i].tat);
    }
    printf("Average: %.2f\n", sum / n);
}

void waiting_time(int n, struct process p[])
{
    printf("\nWaiting Time:-\n");
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (p[i].wt = p[i].tat - p[i].bt);
        printf("P%d: %.2f\n", p[i].id, p[i].wt);
    }
    printf("Average: %.2f\n", sum / n);
}

void fcfs(int n, struct process p[])
{
    sort(p, 0, n - 1, 0);
    int i = 0;
    float t = p[0].at;
    printf("\nFCFS Scheduling:-");
    printf("\n%.2f", t);
    while (i < n)
    {
        printf("\n    P%d", p[i].id);
        t += p[i].bt;
        p[i].rt = 0;
        p[i].ct = t;
        printf("\n%.2f", t);
        i++;
    }
    printf("\n");
    sort(p, 0, n - 1, 1);
}

int current_shortest(int n, struct process p[], float current_t)
{
    int s = 0;
    while (p[s].rt == 0)
        s++;
    for (int i = 0; i < n; i++)
        if ((p[i].rt > 0) && (p[i].rt < p[s].rt) && (current_t >= p[i].at))
            s = i;
    return s;
}

void sjf(int n, struct process p[])
{
    sort(p, 0, n - 1, 0);
    int completed = 0;
    float t = p[0].at;
    printf("\nSJF Scheduling:-");
    printf("\n%.2f", t);
    while (completed < n)
    {
        int i = current_shortest(n, p, t);
        printf("\n    P%d", p[i].id);
        t += p[i].bt;
        p[i].rt = 0;
        p[i].ct = t;
        printf("\n%.2f", t);
        completed++;
    }
    printf("\n");
    sort(p, 0, n - 1, 1);
}

void rr(int n, struct process p[], float time_q)
{
    sort(p, 0, n - 1, 0);
    int completed = 0, i = 0;
    float t = p[0].at;
    printf("\nRound Robin Scheduling:-");
    printf("\n%.2f", t);
    while (completed < n)
    {
        if (t < p[i].at || p[i].rt == 0)
        {
            i = (i + 1) % n;
            continue;
        }
        printf("\n    P%d", p[i].id);
        if (p[i].rt <= time_q)
        {
            t += p[i].rt;
            p[i].rt = 0;
            p[i].ct = t;
            completed++;
        }
        else
        {
            t += time_q;
            p[i].rt -= time_q;
        }
        printf("\n%.2f", t);
        i = (i + 1) % n;
    }
    printf("\n");
    sort(p, 0, n - 1, 1);
}

int current_priority(int n, struct process p[], float current_t)
{
    int s = 0;
    while (p[s].rt == 0)
        s++;
    for (int i = 0; i < n; i++)
        if ((p[i].rt > 0) && (p[i].priority < p[s].priority) && (current_t >= p[i].at))
            s = i;
    return s;
}

void priority(int n, struct process p[])
{
    sort(p, 0, n - 1, 0);
    int completed = 0;
    float t = p[0].at;
    printf("\nPriority Scheduling:-");
    printf("\n%.2f", t);
    while (completed < n)
    {
        int i = current_priority(n, p, t);
        printf("\n    P%d", p[i].id);
        t += p[i].bt;
        p[i].rt = 0;
        p[i].ct = t;
        printf("\n%.2f", t);
        completed++;
    }
    printf("\n");
    sort(p, 0, n - 1, 1);
}

int main()
{
    int n;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d:-\n", (p[i].id = i + 1));
        printf("Enter Burst Time: ");
        scanf("%f", &p[i].bt);
        p[i].rt = p[i].bt;
        printf("Enter Arrival Time: ");
        scanf("%f", &p[i].at);
    }

    int o;
    printf("\nSelect the scheduling algorithm\n1) FCFS\n2) SJF\n3) Round Robin\n4) Priority\n: ");
    scanf("%d", &o);
    if (o == 1)
    {
        display_process(n, p, 0);
        fcfs(n, p);
    }
    else if (o == 2)
    {
        display_process(n, p, 0);
        sjf(n, p);
    }
    else if (o == 3)
    {
        display_process(n, p, 0);
        float time_q;
        printf("Enter Time Quantum: ");
        scanf("%f", &time_q);
        rr(n, p, time_q);
    }
    else if (o == 4)
    {
        printf("\nEnter Priority of\t\t(1 - Highest)\n");
        for (int i = 0; i < n; i++)
        {
            printf("P%d: ", p[i].id);
            scanf("%d", &p[i].priority);
        }
        display_process(n, p, 1);
        priority(n, p);
    }
    else
    {
        printf("\nInvalid Entry\n");
        return 1;
    }

    turnaround_time(n, p);
    waiting_time(n, p);
    return 0;
}