
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void asc(int a[], int n)
{
int i,j,t;
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j])
{
t=a[i]; a[i]=a[j]; a[j]=t;
}
printf("sorted array elements in ascending order are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}

void dsc(int a[], int n)
{
int i,j,t;
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]<a[j])
{
t=a[i]; a[i]=a[j]; a[j]=t;
}
printf("sorted array elements in descending order are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}

int main()
{
pid_t pid;
int a[50],n,i;

printf("enter the size of the array\n");
scanf("%d",&n);

printf("enter element of %d size array\n",n);
for(i=0;i<n;i++)
{
printf("a[%d]:",i);
scanf("%d",&a[i]);
}

pid=fork();

switch(pid)
{
case -1:
printf("Error in fork\n");
exit(-1);

case 0:
printf("child process\n");
asc(a,n);
exit(0);

default:
wait(NULL);
printf("Parent process\n");
dsc(a,n);
exit(0);
}
}
