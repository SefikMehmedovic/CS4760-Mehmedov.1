#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
 
	int opt, x;
	FILE *fp;
	
	while((opt = getopt(argc,argv, "n:hp")) != -1)
	{
		switch(opt)
		{
	   	  case 'h':
			printf("The program takes 2 different arguments\n");
			printf("-n is the process chain ad it requires a variable value\n");
			printf("-p is to test perror\n");
			break;
		 case 'n':
			x = atoi(optarg);
			printf("Entered: ", x);
			
			break;
		
		case 'p': 
			fp = fopen("file.txt","r");
			if( fp == NULL)
				{
					perror("Error: ");
					return(-1); //exit due to error
				}
			break;
		default:
			fprintf(stderr, "%s: option '-%c' is invalid: ignored \n", argv[0], optopt);
		}	

	} 
		
        pid_t childpid = 0;
        int i, n;

        if(argc != 2) {
                fprintf(stderr, "Usage: %s processes\n", argv[0]);
                return 1;
        }

        n = atoi(argv[1]);
        for( i = 1; i < n; i++){
                if(childpid = fork())
                break;
        }

        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);

        return 0;
}
