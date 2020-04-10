#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char c[10][7],temp[5];
int i,j,processtime[10],waitingtime[10],totalwaitingtime=0,pr[10],temp1,n;
float averagewaitingtime;
int et[0];
printf("enter no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process%d name:",i+1);
scanf("%s",c[i]);
printf("enter process time:");
scanf("%d",&processtime[i]);
printf("enter priority:");
scanf("%d",&pr[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(pr[i]>pr[j])
{
temp1=pr[i];
pr[i]=pr[j];
pr[j]=temp1;
temp1=processtime[i];
processtime[i]=processtime[j];
processtime[j]=temp1;
strcpy(temp,c[i]);
strcpy(c[i],c[j]);
strcpy(c[j],temp);
}
}
}
waitingtime[0]=0;
for(i=1;i<n;i++)
{
waitingtime[i]=waitingtime[i-1]+et[i-1];
totalwaitingtime=totalwaitingtime+waitingtime[i]-1;
}  
averagewaitingtime=(float)totalwaitingtime/n+1/2;  
printf("process_name\t process_time\t    priority\t waiting_time\n");
for(i=0;i<n;i++)  
{
printf(" \t%s\t\t %d\t\t %d\t\t %d\n" ,c[i],processtime[i],pr[i],waitingtime[i]);
}
printf("total waiting time=%d\n avg waiting time=%f",totalwaitingtime,averagewaitingtime);
return 0;
}
