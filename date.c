#include <stdio.h>
#include <time.h>
#include <string.h>

#define UTC (-5)

int main(int argc, char *argv[100])
{

	time_t local_time;
	//time_t gobal_time = time(NULL);
	struct  tm *ptr;

	char arr[1000];


	local_time = time(NULL);

	if(argv[1]==NULL)
	{
		local_time = time(NULL);
		printf(ctime(&local_time));

	}
	else if(strcmp(argv[1],"-u")==0)
	{
		
		//time(global_time);
		ptr = gmtime(&local_time);
		strftime(arr, 1000, "%c", ptr);
		printf("%s\n",arr );
	}
	else if(strcmp(argv[1],"-R")==0)
	{
		ptr = localtime(&local_time);
		strftime(arr, 1000, "%a %d %h %Y %T %z", ptr);
		printf("%s\n",arr );
	}


	// time_t local_time = time(NULL);
	// time_t global_time = time(NULL);
	// struct tm *time_gm;
	// time_gm = gmtime(&global_time);
	// //printf(ctime(&local_time));
	// if(argv[1] == NULL)
	// {
	// 	printf(ctime(&local_time));
	// }
	// else if(argv[1] = "-u")
	// {
	// 	printf(tm);
	// 	//printf(" %s", ctime(&global_time));
	// }
	// return 0;
}