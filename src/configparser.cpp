#include "configparser.h"
#include "stringutils.h"

#define DEFAULT_CONFIG_PATH "/etc/spider/config"
#define DEFAULT_MODULE_PATH "/var/module"
#define DEFAULT_DEPTH 3
#define DEFAULT_LOGPATH "/var/spider.log"
#define BUFLINE 4096
#define MAX_JOB_MUM "max_job_num"
#define SEED_PATH "seed_path"
#define INCLUDE_PREFIXES "include_prefixes"
#define EXCLUDE_PREFIXES "exclude_prefiex"


typedef struct Config{
        int max_job_num;
        char *seed;
        char *include_prefixes;
        char *exclude_prefixes;
        char *logfile;
        int log_level;  //log级别你
        int max_depth;　//深度
        int make_hostdir;  //host　dir
        int stat_interval; //
        char * module_path;
        vector<char *> modules;
        vector<char *> accept_types;
}



Config *initconfig(){
	
	Config *config=(*config)malloc(sizeof(Config));
	config->max_jon_num=1;
	config->seed=NULL;
	config->include_prefixes=NULL;
	config->exclude_prefixes=NULL;
	config->logfile= DEFAULT_LOGPATH;
	config->log_level=0;
	config->max_depth= DEFAULT_DEPTH;
	config->make_hostdir=NULL;
	config->stat_interval=1;
	config->module_path=DEFAULT_CONFIG_PATH;
	config->modules=NULL;
	config->accept_type =NULL;
	
	return config;
	
}
void loadconfig(Config *config){
	if(config==NULL){
		//TODO log.e
	}

	FILE *confFile;
	char buff[BUFLINE];
	char **splitStrs;
	int count;
	
	confFile = *fopen(DEFAULT_CONFIG_PATH, "r");
        while(fgets(buff, BUFLINE, confFile)!=NULL){
		splitStrs=split(buff,'=',&count);
		if(count==2){
			if(strcmp(buff[0]==))
		}
	}			
	
}
