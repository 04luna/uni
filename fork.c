// Process creation - fork
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
 pid_t pid; 
 int i,j,k,n; 
 int esum=0,osum=0,tsum=0; 

 printf("\nBefore Call of fork "); 
 printf("\nEnter the value of n"); 
 scanf("%d", &n); 
 pid=fork(); 
 if(pid==0)   
{ 
  printf("\nWe are in the child process" ); 
   
   for(i=2;i<=n;i=i+2) 
   esum=esum+i; 
   printf("\nThe sum of even terms is %d", esum); 
} 
 else 
{ 
  printf("\nWe are in parent process"); 
    for(j=1;j<=n;j=j+2) 
   osum=osum+j; 
   printf("\nThe sum of odd terms is %d", osum); 
} 
   tsum=esum+osum; 
   printf("\nThe sum of the terms is  %d", tsum); 
  
printf("\nBack to main");   
return 0; 
} 