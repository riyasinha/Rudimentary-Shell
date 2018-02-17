#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#define HISTORY_MAX_SIZE 100

int main(int argc, char *argv[100])
{
	char *arr_pathls;
	arr_pathls=realpath("./ls",NULL);
	char *arr_pathdate;
	arr_pathdate=realpath("./date",NULL);
	char *arr_pathmkdir;
	arr_pathmkdir=realpath("./mkdir",NULL);
	char *arr_pathrm;
	arr_pathrm=realpath("./rm",NULL);
	char *arr_pathcat;
	arr_pathcat=realpath("./cat",NULL);

	static const char *history[1000];
	static  unsigned history_count = 0;


	while(1)
	{

		//char *res = realpath()
		pid_t pid;
		printf("Rudimentary Shell:$ " );
		// printf("lala");
		 char *command;
		 size_t size = 32;
		 command = malloc(sizeof(char)*size);

		 size_t word =getline(&command, &size, stdin);
		 command[strlen(command)-1] = NULL; 
		 // fgets(command,100,stdin);

		//printf("%s\n",command);
		 int flag = 0;

		char *arr = strtok(command," \n");
		//printf("%s\n", arr );
		//  //char * arr;
		//char **list=malloc(sizeof(char)*1024);
		char list[100][100];
		//  //printf("%s\n",arr);
		//  //arr = strtok(command," ");
		int p=0;
		 while(arr!=NULL)
		{
			
			strcpy(list[p],arr);
			p++;
			//printf("%s\n",arr);
			arr=strtok(NULL," \n");
			
		}
		
		history[history_count++] = strdup( list[0] );
		//printf("%s\n",&p );
		if(strcmp(list[0],"echo")==0)
		{
			int i;

			//while(i<=p)
			//{
				if(strcmp(list[1],"-n")==0)
				{
					//printf("entered echo -n");
					i=2;
					//printf("%s",&p );
					while(i<=p)
					{
						printf("%s ",list[i] );
						i++;
					}					//printf("%s\n",list[i++] );
				}
				else if(strcmp(list[1],"-e")==0)
				{
					printf("entered echo -e");
					char val[100];
					printf(">");
					scanf("%s",&val);
					// i=2;
					// //while(i<p)
					// //{
					// 	printf(" %s",list[i] );
						
					// //}
						printf("%s\n",strcat(list[2],val) );
					// printf("%s", list[p]);
					// printf("%s",val );
					printf("\n");

				}
				else
				{
					i=1;
					while(i<=p)
					{
						printf("%s ",list[i]);
						i++;
					}
					printf("\n" );
				}
				
			//}
			
		}
		//printf("%s....\n", list[0]);
		if(strcmp(list[0],"exit")==0)
		{
			//printf("%s\n", "fuck off");
			return 0;
		}
		if(strcmp(list[0],"pwd")==0)
		{
			char cwd[1024];
			getcwd(cwd,sizeof(cwd));
			printf("Directory is : %s\n", cwd );
		}
		if(strcmp(list[0],"cd")==0)
		{
			if(list[1] == NULL || !strcmp(list[1],""))
			{
				printf("not supported, please enter an arguement with cd\n" );
				chdir(getenv("HOME"));
			}
			else if(!strcmp(list[1],".."))
			{
				chdir("..");
			}
			else
			{
				if(chdir(list[1])==-1)
				{
					printf("%s: no such directory\n", list[1]);
				}
				
			}
		}
		if(strcmp(list[0],"history") == 0)
		{
			int i;
			i=0;
			printf("Printing History:\n");
			
			while(history!=NULL)
			{
				if(history[i]==NULL)
				{
					break;
				}
				printf("%s\n",history[i] );
				i++;
			}
		}
		if(strcmp(list[0],"date")==0)
		{
			//printf("lala\n" );
			char pid = fork();
			if(pid<0)
			{

				fprintf(stderr, "Fork Failed");
				return 1;
			}
			else if(pid==0)
			{
				//execl()
				//printf("hello\n");
				if(!strcmp(list[1],"")){
					execl(arr_pathdate, arr_pathdate ,NULL);
			}
			else {
				execl(arr_pathdate ,arr_pathdate ,list[1],NULL);
			}
				
			}
			else
			{
				wait(NULL);
				//printf("Child Complete\n");
			}
			//execl("/home/riya/Desktop/src/date.c",list,NULL);
		}
		if(strcmp(list[0],"ls")==0)
		{
			pid = fork();
			if(pid<0)
			{
				fprintf(stderr, "Fork Failed");
				return 1;
			}
			else if(pid==0)
			{
				if(!strcmp(list[1],""))
				{
					execl(arr_pathls, arr_pathls, NULL );
				}
				else if (!strcmp(list[2],""))
				{
					execl(arr_pathls, arr_pathls, list[1],NULL );
				}
				else
				{
					execl(arr_pathls, arr_pathls,list[1],list[2], NULL );
				}
				
			}

			else
			{
				wait(NULL);
			}
		}
		if(strcmp(list[0],"mkdir")==0)
		{
			pid = fork();
			if(pid<0)
			{
				fprintf(stderr, "Fork Failed");
				return 1;
			}
			else if(pid==0)
			{
				if(!strcmp(list[1],""))
				{
					printf("Error :Enter with arguements\n");
				}
				else if(!strcmp(list[2],""))
				{
					execl(arr_pathmkdir,arr_pathmkdir,list[1],NULL);
				}
				else 
				{
					execl(arr_pathmkdir,arr_pathmkdir,list[1],list[2], NULL);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		if(strcmp(list[0],"rm")==0)
		{
			pid = fork();
			if(pid<0)
			{
				fprintf(stderr, "Fork Failed");
				return 1;
			}
			else if(pid==0)
			{
				if(!strcmp(list[1],""))
				{
					printf("Error :Enter with arguements\n");
				}
				else if(!strcmp(list[2],""))
				{
					execl(arr_pathrm,arr_pathrm,list[1],NULL);
				}
				else 
				{
					execl(arr_pathrm,arr_pathrm,list[1],list[2], NULL);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		if(strcmp(list[0],"cat")==0)
		{
			pid = fork();
			if(pid<0)
			{
				fprintf(stderr, "Fork Failed");
				return 1;
			}
			else if(pid==0)
			{
				if(!strcmp(list[1],""))
				{
					printf("Error :Enter with arguements\n");
				}
				else if(!strcmp(list[2],""))
				{
					execl(arr_pathcat,arr_pathcat,list[1],NULL);
				}
				else 
				{
					execl(arr_pathcat,arr_pathcat,list[1],list[2], NULL);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		free(command);
		//free(list);
		memset(list,0,100*100*sizeof(list[0][0]));
	}
}
