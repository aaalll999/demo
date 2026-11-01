
#include <stdio.h>
#include <stdlib.h>

int main()
{
int RQ[100],n,i,j,initial,size,move,total=0,index=0;

printf("Enter the number of Requests\n");
scanf("%d",&n);

printf("Enter the Requests sequence\n");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);

printf("Enter initial head position\n");
scanf("%d",&initial);

printf("Enter total disk size\n");
scanf("%d",&size);

printf("Enter the head movement direction for high 1 and for low 0\n");
scanf("%d",&move);

for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
if(RQ[j]>RQ[j+1])
{
int temp=RQ[j];
RQ[j]=RQ[j+1];
RQ[j+1]=temp;
}

while(index<n && initial>=RQ[index])
index++;

if(move==1)
{
for(i=index;i<n;i++)
{
total+=abs(RQ[i]-initial);
initial=RQ[i];
}
total+=abs(size-1-initial);
initial=size-1;

for(i=index-1;i>=0;i--)
{
total+=abs(RQ[i]-initial);
initial=RQ[i];
}
}
else
{
for(i=index-1;i>=0;i--)
{
total+=abs(RQ[i]-initial);
initial=RQ[i];
}
total+=abs(initial);
initial=0;

for(i=index;i<n;i++)
{
total+=abs(RQ[i]-initial);
initial=RQ[i];
}
}

printf("Total head movement is %d",total);
return 0;
}
