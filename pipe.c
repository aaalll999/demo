
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
int p1[2],p2[2],n;
char path[256],buffer[1024];

pipe(p1);
pipe(p2);

printf("Enter file path: ");
fgets(path,sizeof(path),stdin);
path[strcspn(path,"\n")]='\0';

if(fork()==0)
{
close(p1[1]);
close(p2[0]);

n=read(p1[0],path,sizeof(path));
path[n]='\0';

FILE *f=fopen(path,"r");

if(f==NULL)
{
char msg[]="Could not open file.\n";
write(p2[1],msg,strlen(msg));
}
else
{
while((n=fread(buffer,1,sizeof(buffer),f))>0)
write(p2[1],buffer,n);
fclose(f);
}

close(p1[0]);
close(p2[1]);
exit(0);
}
else
{
close(p1[0]);
close(p2[1]);

write(p1[1],path,strlen(path)+1);
close(p1[1]);

printf("\nFile content:\n");

while((n=read(p2[0],buffer,sizeof(buffer)))>0)
write(1,buffer,n);

close(p2[0]);
wait(NULL);
}

return 0;
}
