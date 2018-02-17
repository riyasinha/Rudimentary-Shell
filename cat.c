#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc , char* argv[])
{
	FILE *file;

	char fname[200];
	char c;

	size_t length =0;
	ssize_t r;
	char *cc = NULL;
	
	if(argc==2)
	{
		file = fopen(argv[1],"r");
		c = fgetc(file);
		while(c!=EOF)
		{
			printf("%c",c );
			c = fgetc(file);
		}
		fclose(file);
	}
	if(argc==3)
	{
		if(!strcmp(argv[1],"-e"))
		{
			file = fopen(argv[2],"r");
			//c = fgetc(file);
			int cnt =0;
			while((r = getline(&cc, &length,file))!=-1)
			{
				cnt++;
				printf("%d-%s",cnt,cc);
				//printf("\n");
				//c = fgetc(file);
				// printf("$\n");
			}
			//printf("$\n");
			fclose(file);
		}
		if(!strcmp(argv[1],"-A"))
		{
			file = fopen(argv[2],"r");
			//c = fgetc(file);
			int cnt =0;
			while((r = getline(&cc, &length,file))!=-1)
			{
				cnt++;
				printf("%d-%s",cnt,cc);
				//printf("\n");
				//c = fgetc(file);
				// printf("$\n");
			}
			//printf("$\n");
			fclose(file);
		}
	
	

	}
}

// scanf("%s",fname);
	// printf("%s\n",fname);
	// if(strcmp(argv[2],"Z")==0)
	// {
		// file = fopen(fname,"r");
		// c = fgetc(file);
		// while(c!=EOF)
		// {
		// 	printf("%c",c );
		// 	c = fgetc(file);
		// }
		// fclose(file);