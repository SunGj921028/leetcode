//Palindrome Number
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool isPalindrome(int x){
    int sum=0;
    if(x<0||(x%10==0&&x!=0)){
        return false;
    }
    while(x>sum){
        sum = sum*10 + x%10;
        x/=10;
    }
    if(x==sum||x==sum/10){
        return true;
    }else{
        return false;
    }
}
int x=0;
int main(){
    scanf("%d",&x);
    isPalindrome(x);
}