#include <stdio.h>
struct PCB
{
    int pid, arrival, burst, ta;
};
void pline(int x);
int main()
{
    int i, num, j;
    float avg = 0.0, sum = 0.0;
    struct PCB p[10], temp;
    printf("Enter number of Process: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("Enter Arrival time and Burst Time for the Process Id : %d ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].pid = i + 1;
    }
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        sum = sum + p[i].burst;
        p[i].ta = sum;
    }
    sum = 0;
    pline(74);
    printf("PID \tArrival\t\tBurst\tExittime\tTurnaround\tWaitingtime\n");
    pline(74);
    float wt = 0;
    for (i = 0; i < num; i++)
    {
        printf("%d \t%d\t \t%d\t\t%d\t \t%d\t\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].ta, p[i].ta - p[i].arrival, (p[i].ta - p[i].arrival) - p[i].burst);
        sum += (p[i].ta - p[i].arrival);
        wt += (p[i].ta - p[i].arrival) - p[i].burst;
    }
    pline(74);
    avg = sum / (float)num;
    float avgwt = 0;
    avgwt = wt / (float)num;
    printf("\n Totat TA: %f.", sum);
    printf("\n Avg TA: %.3f.", avg);
    printf("\n Avg WT: %.3f", avgwt);
    printf("\n");
    return 0;
}
void pline(int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        printf("-");
    }
    printf("\n");
}