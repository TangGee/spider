#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include <vector.h>
int DEBUG=1;



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

extern Config *initconfig();
extern void loadconfig(Config *conf);

#endif
