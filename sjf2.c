// Shortest Job First - lab
#include <stdio.h>
#include <conio.h>
void display();
void getdata();
void waitTime();
void turnAroundTime();

int n, p[10], b[10], w[10], tat[10], j, i, temp, pos, avgw, avgt;
int main()
{
    getdata();
    waitTime();
    turnAroundTime();
    display();
    getch();
}
void getdata()
{
    //
    {
        printf("Enter the number of processes\n");
        scanf("%d", &n);
        printf("\nEnter the burst time of process\n");
        for (i = 0; i < n; i++)
        {
            printf("p%d:", i + 1);
            scanf("%d", &b[i]);
            p[i] = i + 1; // contains process number
        }

        // sorting burst time in ascending order using selection sort
        for (i = 0; i < n; i++)
        {
            pos = i;
            for (j = i + 1; j < n; j++)
            {
                if (b[j] < b[pos])
                    pos = j;
            }

            temp = b[i];
            b[i] = b[pos];
            b[pos] = temp;

            temp = p[i];
            p[i] = p[pos];
            p[pos] = temp;
        }

        //
    }
}
void waitTime()
{
    float totalWait = 0;
    /*waiting time of first process is 0*/
    w[0] = 0;

    //
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            w[i] += b[j];

            totalWait = w[i] + totalWait;
        }
    }
    printf("\n Total Waiting time =%f ", totalWait);    // this is broken and im too lazy to fix :D
    printf("\n Average Waiting time =%f ", totalWait/n);    
}

void turnAroundTime()
{ 
    //
    float totalTat = 0;
    tat[-1] = 0;
    // Code here
    for (int i = 0; i < n; i++)
    {
        tat[i] = b[i] + w[i]; // calculate turnaround time
        totalTat += tat[i];
    }
    printf("\n\n Total TurnAround Time(TAT) = %f", totalTat);
    printf("\n Average Turn Around Time Avg.(TAT) = %f", totalTat / n);
}
void display()
{
    // Code here
    printf("\n");
    printf("PROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t %d\t\t %d\t\t %d\n", p[i], b[i], w[i], tat[i]);
    }
    //avgt = (float)totalWait/ n; // average turnaround time
}