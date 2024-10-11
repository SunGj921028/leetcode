#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        sort(order.begin(), order.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> emptySeats; // Min heap(由小到大, top()是最小的)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> takenSeats;

        for (int i = 0; i < n; ++i) emptySeats.push(i);

        for (int i : order) {
            int arrival = times[i][0], leave = times[i][1];

            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second);
                takenSeats.pop();
            }

            int seat = emptySeats.top();
            emptySeats.pop();

            if (i == targetFriend) return seat;

            takenSeats.push({leave, seat});
        }
        return -1;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<vector<int> > times = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend = 1;
    cout << obj->smallestChair(times, targetFriend) << "\n";
    return 0;
}