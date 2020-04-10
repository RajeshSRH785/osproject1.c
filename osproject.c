#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
int c[10][7],temp[5];
int i,j,pt[10],waiting_time[10],totalwaitingtime=0,rk[10],temp1,n;
float averagewaitingtime;
int et[0];
printf("enter no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process%d name:",i+1);
scanf("%s",c[i]);
printf("Enter process time:");
scanf("%d",&pt[i]);
printf("enter priority:");
scanf("%d",&rk[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(rk[i]>rk[j])
{
temp1=rk[i];
rk[i]=rk[j];
rk[j]=temp1;
temp1=pt[i];
pt[i]=pt[j];
pt[j]=temp1;
strcpy(temp,c[i]);
strcpy(c[i],c[j]);
strcpy(c[j],temp);
}
}
}
waiting_time[0]=0;
for(i=1;i<n;i++)
{
waiting_time[i]=waiting_time[i-1]+et[i-1];
totalwaitingtime=totalwaitingtime+waiting_time[i]-1;
}  
averagewaitingtime=(float) totalwaitingtime/n+1/2;  
printf("Process Name\t Process Time\t priority      Waiting time\n");
for(i=0;i<n;i++)  
{
 printf(" %s\t       %d                  %d\t \t\t%d\n" ,c[i],pt[i],rk[i],waiting_time[i]);;
}
printf("Total Waiting Time=%d\n Avg. Waiting Time=%f", totalwaitingtime,averagewaitingtime);
}
