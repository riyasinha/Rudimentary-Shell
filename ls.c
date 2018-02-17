#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc , char* argv[])
{
	struct dirent *f;
	struct  stat stats;
	DIR *directory;

	char arr[512];

	if(argc==1)
	{
		printf("\n");
		char cwd[1024];
		getcwd(cwd,sizeof(cwd));
		directory = opendir(cwd);
		printf("%s\n",cwd );
	while((f = readdir(directory)) !=NULL)
	{
		sprintf(arr,"%s/%s",cwd,f->d_name);
		stat(arr,&stats);
		//printf("%zu",stats.st_size );
		printf(" %s\n",f->d_name );
	}
		//printf("Directory is : %s\n", cwd );
	}
	if(argc == 2)
	{
		printf("\n");
		directory = opendir(argv[1]);
		printf("%s\n",argv[1] );
		while((f = readdir(directory)) !=NULL)
		{
			sprintf(arr,"%s%s ",argv[1],f->d_name);
			stat(arr,&stats);
			//printf("%zu ",stats.st_size );
			printf("%s\n ",f->d_name );
		}

	}

	if(argc==3)
	{
		if(strcmp(argv[1],"-a")==0)
		{
			printf("huhu\n");
			if(strcmp(argv[2],"")!=0)
			{
			directory = opendir(argv[2]);
			printf("%s\n",argv[2] );
			while((f = readdir(directory)) !=NULL)
			{
				sprintf(arr,"%s%s",argv[1],f->d_name);
				stat(arr,&stats);
				//printf("%zu",stats.st_size );
				printf("%s\n",f->d_name );
			}
			}
			else{
				printf("Enter an argument after the option.\n");
			}
		}
		else if(strcmp(argv[1],"-c")==0)
		{
			if(strcmp(argv[2],"")!=0)
			{
			printf("\n");
			directory = opendir(argv[2]);
			while((f = readdir(directory)) !=NULL)
			{
				sprintf(arr,"%s%s",argv[1],f->d_name);
				stat(arr,&stats);
				//printf("%zu",stats.st_size );
				printf("%s\n",f->d_name );
			}
			}
			else
			{
				printf("Enter an argument after the option.\n");
			}
		}
	}

	close(directory);
	return 0;

}