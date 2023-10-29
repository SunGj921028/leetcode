#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int lengthOfLastWord(char * s){
    int count=0;
    bool ok=false;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]!=' '){
            ok=true;
            count++;
        }else if(s[i]==' ' && ok){
            break;
        }
    }
    return count;
}

int main(){
    char s[100];
    scanf("%s",s);
    printf("%d",lengthOfLastWord(s));
    return 0;
}