# include <stdio.h> 
# include <unistd.h> 
# include <stdlib.h> 
# include <string.h>
# include <sys/types.h>
int main()
{
	int fd1[2];
	int fd2[2];
	pid_t childpid;
	pipe(fd1);
	pipe(fd2);
	
	childpid=fork();
	if(childpid == -1){
		perror("fork");
		exit(0);
	}
	if(childpid==0){
		int sum=0;
		int a=0;
		while(a!=-1)
		{
			scanf("%d",&a);
			write (fd1 [1] ,&a,1);
		}
		read(fd2[0],&sum,sizeof(sum));
		printf("The sum calculated is %d\n",sum-255);
		exit(0);
	}
	else
	{
		int sum=0;
		int a=0;
		while(a!=255)
		{
			read(fd1[0],&a,1);
			sum=sum+a;
		}
		write(fd2[1],&sum,sizeof(sum));
	}
}
