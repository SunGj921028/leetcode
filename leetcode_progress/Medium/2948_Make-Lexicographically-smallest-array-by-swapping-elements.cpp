#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end()); // In ascending order.

        int currGroup = 0; // Initially, the first element is in group 0.
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for(int i = 1; i < nums.size(); i++){
            if(abs(numsSorted[i] - numsSorted[i - 1]) > limit){
                currGroup++; // New group.
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if(groupToList.find(currGroup) == groupToList.end()){
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for(int i = 0 ; i < nums.size(); i++){
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;
    vector<int> ans = s.lexicographicallySmallestArray(nums, limit);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}