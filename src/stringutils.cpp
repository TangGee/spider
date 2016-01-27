#include "stringutils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "spider.h"

extern int DEBUG;
/**
 * 确保strbu士放在全局区的 并且会毁坏str
 */
char* trim(char* str){
	if(str==NULL)
		return NULL;
	int len = strlen(str);
	char *start=str;
	char *end = str+len-1;
	while(1){
		if(isspace(*start)){
			start++;
		}else{
			break;
		}
	}
	while(start<end){
		  if(isspace(*end)){
                        end--;
                }else{
                        break;
                }
	}

	if(end<str+len){
		*(end+1) = '\0';
	}
	
	return start;
}


char **split(char *line,char c, int *count){
	if(line==NULL){
		return 	NULL;
	}
	char *str=line;
	char **vector=NULL;
	char *temp;
	
	while((temp=strchr(str,c))!=NULL){
		(*count)++;
		vector=(char **) realloc(vector,(*count)*sizeof(char *));
		vector[(*count)-1] = trim(str);
		str=temp+1;
	}

	vector[(*count)] = trim(str);
	if(DEBUG){
		printf("%s  %d",line,(*count));
	}

	return vector;

}


int main(int argc,char **argv ){
	char str[]=" a=b = c  ";
//	char str2[100]="    ";
//	char *aa=trim(str);
//	printf("%s",aa);
//	char *bb=trim(str2);
//	printf("%s",bb);
	int count;
	char **xx=split(str,'=',&count);
	for(int i=0;i<count;i++){
		printf("%s\n",xx[i]);
	}
}
