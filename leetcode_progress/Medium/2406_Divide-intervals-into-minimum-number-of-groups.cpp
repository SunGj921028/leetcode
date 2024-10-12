#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int > start_times, end_times;
        // Extract start and end times
        for (auto interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int ans = 0;
        int endPtr = 0;
        for(int start : start_times){
            if(start > end_times[endPtr]){ // Two intervals are in the same group
                endPtr++;
            } else {
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<vector<int> > intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << obj->minGroups(intervals) << "\n"; // 3
    return 0;
}