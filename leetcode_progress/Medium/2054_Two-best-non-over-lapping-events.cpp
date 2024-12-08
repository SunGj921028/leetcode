#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // Sort by start time
        });

        vector<int > suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int maxSum = 0;

        // Binary search for the best non-overlapping events
        for(int i = 0; i < n; i++){
            int left = i + 1, right = n - 1;
            int nextEventIdx = -1;

            while(left <= right){
                int mid = left + (right - left) / 2;
                if(events[mid][0] > events[i][1]){
                    nextEventIdx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

            if(nextEventIdx != -1){
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIdx]);
            }

            maxSum = max(maxSum, events[i][2]);
        }

        return maxSum;
    }
};

int main(){}