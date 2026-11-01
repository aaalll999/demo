
#include <stdio.h>
#include <stdlib.h>

int main()
{
int RQ[100],n,i,initial,count=0,total=0;

printf("Enter the number of Requests\n");
scanf("%d",&n);

printf("Enter the Requests sequence\n");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);

printf("Enter initial head position\n");
scanf("%d",&initial);

while(count!=n)
{
int min=1000,d,index=0;

for(i=0;i<n;i++)
{
d=abs(RQ[i]-initial);
if(d<min)
{
min=d;
index=i;
}
}

total+=min;
initial=RQ[index];
RQ[index]=1000;
count++;
}

printf("Total head movement is %d",total);
return 0;
}
