#include<stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[count]=nums[i];
            count++;
        }
    }
    return count;
}

int main(){
    int nums[4]={3,2,2,3};
    int numsSize=4;
    int val=3;
    printf("%d",removeElement(nums,numsSize,val));
    return 0;
}