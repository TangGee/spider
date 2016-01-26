#include "stringutils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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


int main(int argc,char **argv ){
	char str[]=" abckdfasdasd   ";
	char str2[100]="    ";
	char *aa=trim(str);
	printf("%s",aa);
	char *bb=trim(str2);
	printf("%s",bb);
}
