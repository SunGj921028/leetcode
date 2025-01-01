#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n == 1){ return 0;}
        int step = 0;
        int factor = 2; //! Start from 2

        while(n > 1){
            while(n % factor == 0){
                step += factor;
                n /= factor;
            }
            factor++;
        }

        return step;
    }
};

int main(){
    Solution s;
    cout << s.minSteps(3) << endl;
    cout << s.minSteps(9) << endl;
    return 0;
}