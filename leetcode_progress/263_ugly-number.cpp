#include<bits/stdc++.h>

using namespace std;

//! ugly number: 1, 2, 3, 4, 5, 8 ,9 ,10 ,12 ...

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){return false;}

        while(n % 2 == 0){n /= 2;}
        while(n % 3 == 0){n /= 3;}
        while(n % 5 == 0){n /= 5;}

        return n == 1;
    }
};

int main(){
    Solution s;
    cout << s.isUgly(6) << endl;
    cout << s.isUgly(8) << endl;
    cout << s.isUgly(14) << endl;
    return 0;
}

