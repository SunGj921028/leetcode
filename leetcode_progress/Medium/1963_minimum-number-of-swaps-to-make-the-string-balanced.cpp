#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        if(s == "[]" || s == ""){ return 0;}
        int size = 0; //? Count for remaining [ that need to be matched
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        //! After looping through the string, the counter will show how many opening brackets [ remain unmatched
        return (size + 1) / 2;
    }
};

int main(){
    Solution* obj = new Solution();
    string s = "][][";
    string s2 = "]]][[[";
    string s3 = "[]";
    cout << obj->minSwaps(s) << "\n";
    cout << obj->minSwaps(s2) << "\n";
    cout << obj->minSwaps(s3) << "\n";
    return 0;
}