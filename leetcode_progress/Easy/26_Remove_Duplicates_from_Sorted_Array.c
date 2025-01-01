#include<stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int count=0;
    int temp=nums[0];
    nums[count]=nums[0];
    for(int i=0;i<numsSize;i++){
        if(temp!=nums[i]){
            count++;
            nums[count]=nums[i];
        }
        temp=nums[i];
    }
    return count+1;
}

int main(){
    int nums[3]={1,1,2};
    int numsSize=3;
    printf("%d",removeDuplicates(nums,numsSize));
    return 0;
}