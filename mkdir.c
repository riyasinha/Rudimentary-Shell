#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[100])
{
	 if(argc==2)
	 {
	 	struct stat s = {0};
	 	if(stat(argv[1],&s)==-1)
	 	{
	 		mkdir(argv[1],0700);
	 	}
	 }
	 else if(argc==3)
	 {
	 	struct stat s = {0};
	 	if(strcmp(argv[1],"-v")==0)
	 	{
	 		if(stat(argv[2],&s)==-1)
	 		{
	 			mkdir(argv[2],0700);
	 			printf("The Directory has been Created!\n");
	 		}
	 		else
	 		{
	 			printf("Directly is already there!\n");
	 		}
	 		
	 	}
	 	else if(strcmp(argv[1],"-m")==0)
	 	{
	 		struct stat s = {0};
		 	if(strcmp(argv[1],"-m")==0)
		 	{
		 		if(stat(argv[2],&s)==-1)
		 		{
		 			mkdir(argv[2],0777);
		 			//printf("The Directory has been Created!\n");
		 		}
		 		else
		 		{
		 			printf("Directly is already there!\n");
		 		}

		 	}
	 	}
	 }
}