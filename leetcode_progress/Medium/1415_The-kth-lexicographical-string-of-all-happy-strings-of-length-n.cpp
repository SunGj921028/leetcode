#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void generateHappyStrings(int n, int k, string &currString, int &idxInSortedList, string &ans){
        if(currString.size() == n){ 
            idxInSortedList++;
            if(idxInSortedList == k){ ans = currString; }
            return;
        }

        for(char c = 'a'; c <= 'c'; c++){
            if(currString.size() > 0 && currString.back() == c){
                continue;
            }

            currString.push_back(c);

            //! Recursive call
            generateHappyStrings(n, k, currString, idxInSortedList, ans);

            if(ans != ""){ return; }
            //? Backtracking by removing the last character
            currString.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string currString = "";
        string ans = "";
        int idxInSortedList = 0;

        generateHappyStrings(n, k, currString, idxInSortedList, ans);
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.getHappyString(1, 3) << endl;
    return 0;
}