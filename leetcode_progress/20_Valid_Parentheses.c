#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char * s){
    int array[6]={0};
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            array[0]=i+1;
        }else if(s[i]==')'){
            array[1]=i+1;
        }else if(s[i]=='{'){
            array[2]=i+1;
        }else if(s[i]=='}'){
            array[3]=i+1;
        }else if(s[i]=='['){
            array[4]=i+1;
        }else if(s[i]==']'){
            array[5]=i+1;
        }
        if(array[0]>array[1]||array[2]>array[3]||array[4]>array[5]){
            return false;
        }
    }
    /*for(int i=0;i<6;i++){
        printf("%d ",array[i]);
    }*/
    if(array[0]!=0&&array[1]!=0&&array[2]!=0&&array[3]!=0&&array[4]!=0&&array[5]!=0){
        return true;
    }else return false;
}

char s;
int main(){
    scanf("%s",&s);
    isValid(&s);
}