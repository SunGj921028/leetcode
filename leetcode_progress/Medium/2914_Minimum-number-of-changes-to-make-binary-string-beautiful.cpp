#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++){
            if(i % 2 == 1 && s[i] != s[i - 1]){ count++;}
        }
        return count;
    }
};

int main(){
    Solution solution;
    string s = "1001";
    string s2 = "10";
    string s3 = "0000";
    cout << solution.minChanges(s) << endl;
    cout << solution.minChanges(s2) << endl;
    cout << solution.minChanges(s3) << endl;
    return 0;
}