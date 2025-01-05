#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);

        for(auto & shiftOp : shifts){
            int start = shiftOp[0], end = shiftOp[1], dir = shiftOp[2];
            shift[start] += (dir == 1 ? 1 : -1);
            shift[end + 1] -= (dir == 1 ? 1 : -1);
        }

        int currShift = 0;
        for(int i = 0; i < n; i++){
            currShift += shift[i];
            shift[i] = currShift;
        }

        for(int i = 0; i < n; i++){
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};

int main(){
    Solution s;
    string str = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << s.shiftingLetters(str, shifts) << endl;
    return 0;
}