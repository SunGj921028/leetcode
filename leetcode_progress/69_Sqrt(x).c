#include<stdio.h>

int mySqrt(int x){
    int high=x,low=0;
        while(high>low){
            long int mid = low + ((long int)high - low + 1) / 2;
            if(mid*mid<=(long int)x)
                low = mid;
            else
                high = mid -1;
        }
        return low;
}

int main(){
    int x=0;
    scanf("%d",&x);
    printf("sqrt(%d) = %d",x,mySqrt(x));
    return 0;
}