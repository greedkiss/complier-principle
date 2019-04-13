#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
char key[28][10] = {
    "main","if","else","while","do","for","return","+","-","*","/","%",">",">=","<","<=","==","!=","=",";","(",")","{","}","int","float","double","char"
};

int value[] = {1,2,3,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

int main(){
    int flag,wexit;
    FILE *fin, *fout;
    fin = fopen("data.in","r");
    fout = fopen("data.out", "w");
    char s[100];
    while(fscanf(fin, "%s", s) != EOF){
        //数字检索
        flag = 0;
        wexit = 0;
        if(s[0] - '0' >= 0 && s[0] - '0' <=9){
            for(int j = 0;j<strlen(s) ; j++){
                if(s[j] - '0' >= 0 && s[j] - '0' <= 9){
                    flag = 1;
                }else{
                    wexit = 1;
                    break;
                }
            }
        }
        if(wexit){
            cout<<"this is a wrong word"<<" "<<s<<endl;
            continue;
        }
        if(flag){
            fprintf(fout, "( %s , %d ) ",s, 9);
            continue;
        }
        flag = 0;
        //关键字，符号判断,标识符检索
        for(int j = 0; j<28; j++){
            if(s[0] == key[j][0]){
               if(strlen(s) == strlen(key[j])){
                flag = value[j];
                   for(int k = 1 ; k<strlen(s) ; k++){
                       if(s[k] != key[j][k]){
                            flag = 0;
                            break;                      
                       }
                   }
               }
            }
        }
        if(flag){
            fprintf(fout, "( %s , %d ) ",s,flag);
            continue;
        }else{
            fprintf(fout, "( %s , %d ) ",s, 8);
            continue;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
