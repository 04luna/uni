// FCFS - First come first serve - Process scheduling
#include<stdio.h>

void display();
void getInput();
void calculateWaitTime();
void turnAroundTime();

int n, a[100],b[100];

int main(){
    
    printf("------------  First come first serve scheduling -------------\n\n");

    getInput();
    display();
    calculateWaitTime();
    turnAroundTime();
}

void getInput()
{   
    char c;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("\nDo you need to enter the arrival time of process [y/n] or [Y/N]: \n");
    scanf("%s",&c);

    for(int i=0; i<n; i++)
    {
          printf("Enter the process %d burst time : ",i+1);
          scanf("%d",&b[i]);
          if(c=='y' || c=='Y')
          {
                  printf("Enter the %d process arrival time : ",i+1);
                  scanf("%d",&a[i]);
          }
          else
          {
                  a[i]=0;
          }
    }
}

void display()
{
     printf("\nProcess\tBurst Time\tArrival Time\n");
     for(int i=0; i<n; i++)
     {
             printf("    %d\t      %d\t      %d\n",i+1,b[i],a[i]);
     }
}

void calculateWaitTime()
{
     int w[100];
     float totalWait=0;
     w[0]=0;
     for(int i=1; i<n; i++)
     {
           w[i]=b[i-1]-a[i]+w[i-1];
           totalWait=w[i]+totalWait;
     }
     printf("\nTotal Waiting time = %f",totalWait);
     printf("\nAverage Waiting time = %f",totalWait); 
}

void turnAroundTime()
{
     int tat[100];
     float totalTat=0;
     tat[-1]=0;
     for(int i=0; i<n; i++)
     {
             tat[i]=b[i]-a[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\n\nTotal Turn Around Time = %f",totalTat);
     printf("\nAverage Turn Around Time Avg = %f",totalTat/n);
}