#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        deque<int> dq; //? double-ended queue

        for(int i = 0; i < nums.size(); i++){
            // If queue is not empty and the current number is greater than or equal to the last in queue
            if(!dq.empty() && nums[i] >= dq.back()){
                bool skip = false;

                while(!dq.empty()){
                    int add = dq.back();
                    dq.pop_back();
                    if(!skip){
                        score += add;
                    }
                    skip = !skip; //! skip the next element of current element
                }
                continue;
            }

            dq.push_back(nums[i]); //! Add current element to the queue
        }

        //! Final processing of remaining elements in the queue
        bool skip = false;
        while(!dq.empty()){
            int add = dq.back();
            dq.pop_back();
            if(!skip){
                score += add;
            }
            skip = !skip;
        }

        return score;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 1, 3, 4, 5, 2};
    cout << sol.findScore(nums) << endl;
    return 0;
}