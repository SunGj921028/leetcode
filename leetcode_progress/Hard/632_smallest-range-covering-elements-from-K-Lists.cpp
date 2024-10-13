#include<bits/stdc++.h>

using namespace std;

//! The key takeaway is to utilize a min-heap to track the minimum element from each list 
//! and a sliding window to track the range of numbers.

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //? Min-Heap: stores (value, list index, element index)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int> > > minHeap;
        int curMax = INT_MIN;

        //? Initialize the min-heap with the first element from each list
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        //? Track the smallest range
        vector<int> smallRange = {0, INT_MAX};

        while(!minHeap.empty()){
            //* Get the minmum element from the heap
            vector<int> cur = minHeap.top(); // (0, 1, 0)
            minHeap.pop();
            int curMin = cur[0], listIdx = cur[1], eleIdx = cur[2];

            //* Update the smallest range if a better one is found
            if((curMax - curMin < smallRange[1] - smallRange[0]) || 
               (curMax - curMin == smallRange[1] - smallRange[0] && curMin < smallRange[0])){
                smallRange[0] = curMin;
                smallRange[1] = curMax;
            }

            //* Move to the next element in the same list
            if(eleIdx + 1 < nums[listIdx].size()){ //! Check if the current list is out of elements
                int nextVal = nums[listIdx][eleIdx + 1];
                minHeap.push({nextVal, listIdx, eleIdx + 1});
                curMax = max(curMax, nextVal);
            }else{
                break; // If any list is exhausted, stop
            }
        }
        return smallRange;
    }
};
int main(){
    Solution* obj = new Solution();
    vector<vector<int> > nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> ans = obj->smallestRange(nums);
    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}