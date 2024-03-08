#include<iostream>
#include<vector>
#include<unordered_map> //hash table

using namespace std;

class Solution{
    public:
        int singleNumber(vector<int > &nums){
            unordered_map<int, int> num;
            for(auto i : nums){
                num[i]++;
            }

            for(auto i : num){
                if(i.second == 1){
                    return i.first;
                }
            }
            return -1;
        }
};