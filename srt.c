// Shortest remaining time first - Process Scheduling
# include <stdio.h> 
int main() 
{ 
 int i,p[20],a[20],b[20],br[20],tat[20],gantt[100][2],n1,n2,n3,c,d,e=0,f=0,g,time=0,t1,t2,t3,t4,t5,t6; 
 float v1=0.0,v2=0.0; 
 FILE *fp;  
 fp=fopen("sjf.txt","r"); 
 while (fscanf(fp,"%d%d%d",&n1,&n2,&n3)!=EOF) 
 { 
   p[e]=n1; 
   a[e]=n2; 
   b[e]=n3; 
   br[e++]=n3; 
 } 
 while (1) 
 { 
  for (i=1;i<e;i++) 
   if ((br[0]==0 || time<a[0]?1:br[i]<br[0] || (br[i]==br[0] && a[i]<a[0])) && time>=a[i] && br[i]!=0) 
   { 
    t1=p[0]; 
    t2=a[0]; 
    t3=b[0]; 
    t4=br[0]; 
    t5=tat[0]; 

    p[0]=p[i]; 
    a[0]=a[i]; 
    b[0]=b[i]; 
    br[0]=br[i]; 
    tat[0]=tat[i]; 

    p[i]=t1; 
    a[i]=t2; 
    b[i]=t3; 
    br[i]=t4; 
    tat[i]=t5; 
   } 
  if (p[0]>time || br[0]==0) 
  { 
   if (f==0 || gantt[f-1][0]!=-1) 
   { 
    gantt[f][0]=-1; 
    gantt[f++][1]=time; 
   } 
  } 
  else 
  if (br[0]!=0) 
  { 
   if (f==0 || gantt[f-1][0]!=p[0]) 
   { 
    gantt[f][0]=p[0]; 
    gantt[f++][1]=time; 
   } 
   if (--br[0]==0) 
     tat[0]=time+1; 
  } 
  time++; 
  c=0; 
  for (i=0;i<e;i++) 
   if (br[i]!=0) 
    c=1; 
  if (c==0) 
   break; 
 } 

 gantt[f][1]=time; 
 printf ("%8s%8s%8s%8s%8s\n\n","P","A","B","W","TAT"); 
 for (i=0;i<e;i++) 
  printf ("%8d%8d%8d%8d%8d\n",p[i],a[i],b[i],tat[i]-b[i],tat[i]); 
 printf("\n\nAverage waiting time is:"); 
  for(i=0;i<e;i++) 
    v1+=tat[i]-b[i]; 
printf("%f",v1/e); 
printf("\n\nAverage turnaround time is:"); 
  for(i=0;i<e;i++) 
    v2+=tat[i]; 
printf("%f",v2/e); 
printf("\n\n\n"); 

 printf ("\n\n "); 
 for (i=0;i<f;i++) 
  printf ("--- "); 
 printf ("\n|"); 
 for (i=0;i<f;i++) 
  printf (gantt[i][0]==-1?"   |":" %d |",gantt[i][0]); 
 printf ("\n "); 
 for (i=0;i<f;i++) 
  printf ("--- "); 
 printf ("\n0"); 
 for (i=1;i<=f;i++) 
  printf ("  %2d",gantt[i][1]);
  return 0;
}