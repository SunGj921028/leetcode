#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public: 
        vector<int> twoSum(vector<int>& numbers, int target) {
            int slow = 0, fast = numbers.size() - 1;
            while(slow < fast){
                if(numbers[slow] + numbers[fast] == target){
                    return {slow + 1, fast + 1};
                }else if(numbers[slow] + numbers[fast] < target){
                    slow++;
                }else{
                    fast--;
                }
            }
            return {};
        }
};