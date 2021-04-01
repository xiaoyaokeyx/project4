//
//  main.c
//  project4
//
//  Created by yx on 2021/3/30.
//
#define MAX 166
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void dfs(char* s, char** res, int* returnSize, int step, int index, int len, char* tmp)
{
    if (step == 4) {
        res[*returnSize] = (char*)malloc(sizeof(char) * (len + 4));
        tmp[index + step - 1] = '\0';
        strcpy(res[*returnSize], tmp);
        (*returnSize++);
        return;
    }
    if (len - index - 1 <= (3 - step) * 3 && len - index - 1 >= (3 - step) && s[index] != '0') {
        tmp[index + step] = s[index];
        tmp[index + step + 1] = '.';
        dfs(s, res, returnSize, step + 1, index + 1, len, tmp);
    }
    if (len - index - 2 <= (3 - step) * 3 && len - index - 3 >= (3 - step) && s[index] != '0') {
        tmp[index + step] = s[index];
        tmp[index + step + 1] = s[index + 1];
        tmp[index + step + 2] = '.';
        dfs(s, res, returnSize, step + 1, index + 2, len, tmp);
    }
    if (len - index - 3 <= (3 - step) * 3 && len - index - 3 >= (3 - step) && s[index] != '0'
        && (s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + (s[index + 2] - '0') <= 255) {
        tmp[index + step] = s[index];
        tmp[index + step + 1] = s[index + 1];
        tmp[index + step + 2] = s[index + 2];
        tmp[index + step + 3] = '.';
        dfs(s, res, returnSize, step + 1, index + 3, len, tmp);
    }
}
char ** restoreIpAddresses(char * s, int* returnSize){
    *returnSize = 0;
    int len = strlen(s);
    if(len>12 || len<4)return NULL;     //长度不合法直接return

    char** res = (char**)malloc(sizeof(char*)*MAX);
    char* temp =(char*)malloc(sizeof(char)*(len+5));
    dfs(s,res,returnSize,0,0,len,temp);
    return res;
}



int main(int argc, const char * argv[]) {
    char *str = "19268111";
    int returnSize = 0;
    char** res = restoreIpAddresses(str, &returnSize);
    printf("%s\n", res[0]);
}
