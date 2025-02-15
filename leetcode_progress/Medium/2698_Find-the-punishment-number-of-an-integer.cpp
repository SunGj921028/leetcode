#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBePartition(string num, int target){
        // Valid partition found!
        if(num == "" && target == 0){ return true;}
        // Invalid partition found!
        if(target < 0){ return false;}

        for(int i = 0; i < num.size(); i++){
            string left = num.substr(0, i + 1); // [0, i]
            string right = num.substr(i + 1);   // [i + 1, n - 1]
            int leftNum = stoi(left);
            if(canBePartition(right, target - leftNum)){ return true;}
        }
        return false;
    }
    int punishmentNumber(int n) {
        int punishment = 0;

        for(int i = 1; i <= n; i++){
            int squareNum = i * i;
            if(canBePartition(to_string(squareNum), i)){ punishment += squareNum;}
        }
        return punishment;
    }
};

int main(){
    Solution s;
    cout << s.punishmentNumber(37) << "\n";
    return 0;
}