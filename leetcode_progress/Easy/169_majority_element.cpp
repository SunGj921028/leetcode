#include<iostream>
#include<vector>
#include<unordered_map> //hash table

using namespace std;

class Solution{
    public:
        int majorityElement(vector<int > &nums){
            int majorNum = (nums.size() / 2);
            unordered_map<int, int> num;
            for(auto i : nums){
                num[i]++;
            }
            for(auto i : num){
                if(i.second > majorNum){
                    return i.first;
                }
            }
            return -1;
        }
};

// Moore's Voting Algorithm
class Solution2{
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int candidate = 0;
            
            for (int num : nums) {
                if (count == 0) {
                    candidate = num;
                }
                
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
            
            return candidate;
        }
};