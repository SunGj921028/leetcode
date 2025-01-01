#include<bits/stdc++.h>

using namespace std;

//! Two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int amount = 0;
        int maxAmount = 0;
        int left = 0, right = height.size() - 1;
        int containerHeight = 0, containerWidth = 0;

        while(left < right){
            containerWidth = right - left;
            containerHeight = min(height[left], height[right]);
            amount = containerWidth * containerHeight;
            maxAmount = max(maxAmount, amount);
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxAmount;
    }
};

int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
    return 0;
}