#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);

        int idx = 0;
        for(int day = 1; day <= lastDay; day++){
            if(day < days[idx]){
                dp[day] = dp[day - 1];
            }else{
                idx++;
                dp[day] = min({dp[day - 1] + costs[0], dp[max(day - 7, 0)] + costs[1], dp[max(day - 30, 0)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};

int main(){
    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    Solution s;
    int ans = s.mincostTickets(days, costs);
    cout << ans << endl;
    return 0;
}