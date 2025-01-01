#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5){ return false;}
        int five = 0, ten = 0;
        for(auto bill : bills){
            if(bill == 5){
                five++;
            }else if(bill == 10){
                if(five > 0){
                    five--;
                    ten++;
                }else{ return false;}
            }else if(bill == 20){ // change for 15 (10 + 5) or (5 + 5 + 5)
                if((ten <= 0 && five < 3) || (five <= 0)){
                    return false;
                }else if(ten <= 0 && five >= 3){
                    five -= 3;
                }else if(ten > 0){ // This time five at least one, so it can be changed
                    ten--;
                    five--;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> bills = {5,5,5,10,20};
    vector<int> bills2 = {5,5,10,10,20};
    vector<int> wrongcase = {5,5,5,20,20,10,5,10,10,20};
    cout << sol.lemonadeChange(wrongcase) << endl;
    return 0;
}