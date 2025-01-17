#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (auto element : derived) {
            XOR = XOR ^ element;
        }
        return XOR == 0;
    }
};

int main(){
    Solution s;
    vector<int> derived = {1, 1, 0};
    cout << s.doesValidArrayExist(derived) << endl;
    return 0;
}