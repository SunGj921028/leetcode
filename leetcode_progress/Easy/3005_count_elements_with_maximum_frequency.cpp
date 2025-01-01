#include<iostream>
#include<vector>
#include<unordered_map> //hash table

using namespace std;

class Solution{
    public:
        int maxFrequencyElements(vector<int > &nums){
            int maxF = 0;
            int f = 0;
            int numFre[101] = {0};
            for(auto a: nums){
                numFre[a]++;
                if(numFre[a] == maxF){ f++;}
                else if(numFre[a] > maxF){
                    f = 1;
                    maxF = numFre[a];
                }
            }
            return (f * maxF);
        }
};

class Solution2{
    public:
        int maxFrequencyElements(vector<int > &nums){
            unordered_map<int, int> numFre;
            for(int num : nums){
                numFre[num]++;
            }
            int maxF = 0;

            for(auto f : numFre){
                maxF = max(maxF, f.second);
            }

            int maxFreElements = 0;
            for(auto f : numFre){
                if(f.second == maxF){
                    maxFreElements++;
                }
            }

            return (maxF * maxFreElements);
        }
};