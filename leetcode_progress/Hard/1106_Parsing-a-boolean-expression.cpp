#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(')
                continue;  
            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                st.push(currChar);
            }
            else if (currChar == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};

int main(){
    Solution sol;
    cout << sol.parseBoolExpr("!(f)") << endl;
    cout << sol.parseBoolExpr("|(f,t)") << endl;
    cout << sol.parseBoolExpr("&(t,f)") << endl;
    cout << sol.parseBoolExpr("|(&(t,f,t),!(t))") << endl;
    return 0;
}