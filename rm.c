#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(int argc, char *argv[100])
{
	int c;
	if(argc==2)
	{
		struct stat s;
		stat(argv[1],&s);

		if(S_ISREG(s.st_mode)!=0)
		{
			c = remove(argv[1]);
		}

		if(c!=0)
		{
			printf("file doesnt exist\n");
		}
	}

	if(argc==3)
	{
		if(strcmp(argv[1],"-v")==0)
		{
			c= remove(argv[2]);
			if(c==0)
			{
				printf("The file has been deleted\n");
			}
			else
			{
				printf("The file doesnt exist.\n");
			}
			
		}
		else if(strcmp(argv[1],"-f")==0)
		{
			c= remove(argv[2]);

		}
	}
	


}