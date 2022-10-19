// FCFS - lab
#include <stdio.h>
#include <conio.h>
void display();
void getdata();
void waitTime();
void turnAroundTime();
/*we consider that we have max 10 processes*/
/*a is table of arrival time and b of burst time and w waiting time and tat turnaround time*/
int n, a[10], b[10], w[10], tat[10];
int main()
{
    getdata();
    waitTime();
    turnAroundTime();
    display();
    getch();
}
void getdata()
{ /* add code that asks users to enter number of processes then asks user to enter burst time and arrival time of
each process. Below an example of execution where text in black is displayed by the program and text in red is
entered by user:
Enter the number of processes
2
Enter the burst time of process 1
4
Enter the burst time of process 2
7
Enter the arrival time of process 1
0
Enter the arrival time of process 2
2
*/
    // Code here
    {
        printf("Enter the number of processes\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter the burst time of process %d\n", i + 1);
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf("Enter the arrival time of process %d\n", i + 1);
            scanf("%d", &a[i]);
        }
    }
    //
}
void waitTime()
{ /*
 Write here the code which calculates the waiting time of each process and save these values in table w. Display
 then the total waiting time and the average waiting time.
 */
    float totalWait = 0;
    /*waiting time of first process is 0*/
    w[0] = 0;

    // Code here
    for (int i = 1; i < n; i++)
    {
        w[i] = b[i - 1] - a[i] + w[i - 1];
        totalWait = w[i] + totalWait;
    }
    //
    printf("\n Total Waiting time = %f", totalWait);
    printf("\n Average Waiting time = %f", totalWait);
}
void turnAroundTime()
{ /*
 Write here the code which calculates the turnaround time of each process and save these values in table tat.
 Display then the total turn around time and the average turn around time.
 */
    float totalTat = 0;
    tat[-1] = 0;
    // Code here
    for (int i = 0; i < n; i++)
    {
        tat[i] = b[i] - a[i] + tat[i - 1];
        totalTat = totalTat + tat[i];
    }
    //
    printf("\n\n Total TurnAround Time(TAT) = %f", totalTat);
    printf("\n Average Turn Around Time Avg.(TAT) = %f", totalTat / n);
}
void display()
{ /*
 Display as follows:
 PROCESS BURST TIME ARRIVAL TIME WAITING TIME TURNAROUND
 1 4 0 … …
 2 7 2 … …
 */
    // Code here
    printf("\n");
    printf("PROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, b[i], a[i], tat[i]);
    }
    // 
}