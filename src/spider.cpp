#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


static void daemon(){
	pid_t pid;
	if((pid =fork())<0){
		perror("fork");
		exit(1);
	}else if(pid>0){
		exit(1);
	}

	setsid();
}

static void version(){
	printf("version 1.0\n");
	exit(1);
}

static void usage(){
	printf("spider Usage [OPTION]\n"
	" -h\t help\n"
	" -v\t version\n"
	" -d\t run as deamon\n");
	exit(1);
}

int main(int argc,char **argv){
	char ch;
	int daemoned=0;
	while((ch =getopt(argc,argv,"vhd"))!=-1){
		switch(ch){
			case 'v':
				version();
				break;
			case 'd':
				daemoned=1;
				break;
			case 'h':
			case '?':
			default :
				usage();
				break;
		}
	}
	
	if(daemoned==1){
		daemon();
	}

	//解析配置文件

	return 0;
}

