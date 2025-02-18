#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        const int n = pattern.size();
        vector<char> succD(n, 0);
        succD.back() += (pattern.back() == 'D');
        for(int i = n - 2; i >= 0; i--){
            succD[i] = (pattern[i] == 'D') ? succD[i + 1] + 1 : 0;
        }
        string ans(n + 1, ' ');
        iota(ans.begin(), ans.end(), '1'); // fill ans with 1, 2, 3, ..., n
        int i = 0;
        while(i < n){
            if(pattern[i] == 'D'){
                reverse(ans.begin() + i, ans.begin() + i + succD[i] + 1);
            }
            i += succD[i] + 1;
        }
        return ans;
    }
};

class Solution2 { // Using stack
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I') {
                while (!numStack.empty()) {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
            }
        }

        return result;
    }
};

int main(){
    Solution s;
    cout << s.smallestNumber("IIIDIDDD") << endl;
    return 0;
}