#include<bits/stdc++.h>

using namespace std;

//? https://leetcode.com/problems/minimum-time-difference/description/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int min = 0;
        vector<int > minuteArr;
        int totalMinute = 0;
        for(auto s : timePoints){
            int hour = stoi(s.substr(0, 2));
            int minute = stoi(s.substr(3, 2));
            totalMinute = hour * 60 + minute;
            minuteArr.push_back(totalMinute);
            // min = max(min, totalMinute);
        }
        sort(minuteArr.begin(), minuteArr.end());
        // calculate the circular difference
        int circulatDifference = (24 * 60) - minuteArr.back() + minuteArr.front();
        min = circulatDifference;
        // calculate the diff between adjcent times in sorted list
        for(int i = 0; i < minuteArr.size() - 1;i++){
            int tempMin = abs(minuteArr[i] - minuteArr[i + 1]);
            min = min > tempMin ? tempMin : min;
        }
        return min;
    }
};

int main(){
    Solution solution;
    vector<string> timePoints = {"23:59","00:00"};
    vector<string> timePoints2 = {"00:00","23:59","00:00"};
    cout << solution.findMinDifference(timePoints) << endl;
    cout << solution.findMinDifference(timePoints2) << endl;
    return 0;
}