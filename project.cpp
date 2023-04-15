#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, NOP, sum = 0, count = 0, y, quant = 100, wt = 0, tat = 0, a, b;
    double avg_wt, avg_tat;
    printf("Enter the number of processes in the system: ");
    scanf("%d", &NOP);
    
    // Declare arrays to store arrival time, burst time, and remaining time for each process
    int at[NOP], bt[NOP], rt[NOP];
    y = NOP;
    
    // Initialize arrival time and burst time for each process randomly
    for (i = 0; i < NOP; i++) {
        a = rand() % 100 + 1;
        b = rand() % 200 + 100;
        at[i] = a;
        bt[i] = b;
        rt[i] = bt[i]; // remaining time is initially equal to burst time
    }
    
    // Print the table header
    printf("\nProcess No\tBurst Time\tTAT\t\tWaiting Time");
    
    // Perform Round Robin scheduling until all processes are completed
    for (sum = 0, i = 0; y != 0;) {
        if (rt[i] <= quant && rt[i] > 0) {
            sum = sum + rt[i];
            rt[i] = 0;
            count = 1;
        } else if (rt[i] > 0) {
            rt[i] = rt[i] - quant;
            sum = sum + quant;
        }
        if (rt[i] == 0 && count == 1) {
            y = y - 1;
            int tatx = sum - at[i];
            int wtx = sum - at[i] - bt[i];
            printf("\nProcess No[%d]\t%d\t\t%d\t\t%d", i + 1, bt[i], tatx, wtx);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }
    
    // Calculate and print the average waiting time and average turnaround time
    avg_wt = (wt * 1.0) / NOP;
    avg_tat = (tat * 1.0) / NOP;
    printf("\nAverage waiting time: %f", avg_wt);
    printf("\nAverage turnaround time: %f", avg_tat);
    
    return 0;
}
