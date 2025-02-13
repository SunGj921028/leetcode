#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<> > pq(nums.begin(), nums.end());
        int cnt = 0;
        while(pq.size() >= 2 && pq.top() < k){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            pq.push((first * 2) + second);
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    cout << s.minOperations(nums, k) << "\n";
    return 0;
}