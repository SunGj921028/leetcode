#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> result;
            queue<int> q;
            for (int i = 1; i <= 9; ++i) {
                q.push(i);
            }
            while (!q.empty()) {
                int num = q.front();
                q.pop();
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
                if (num > high) {
                    break;
                }
                int lastDigit = num % 10;
                if (lastDigit < 9) {
                    q.push(num * 10 + lastDigit + 1);
                }
            }
            return result;
        }
};