#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    if(target>nums[numsSize-1]){
        return numsSize;
    }else if(target<nums[0]){
        return 0;
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
            return i;
        }else{
            if(target<nums[i+1]&&target>nums[i]){
                return i+1;
            }
        }
    }
    return 0;
}

int main(){
    int nums[4]={1,3,5,6};
    int numsSize=4;
    int target=5;
    printf("%d",searchInsert(nums,numsSize,target));
    return 0;
}