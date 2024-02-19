#include<iostream>

using namespace std;

class Solution {
    public:
        bool isPowerOfThree(int n){
            if(n <= 0){ return false;}
            while(n % 3 == 0){ n /= 3;}
            return n == 1;
        }
};

class Solution2 {
    public:
        bool isPowerOfThree(int n){
            if(n <= 0){ return false;}
            return 1162261467 % n == 0;
        }
};

// recursive
class Solution {
    public:
        bool isPowerOfThree(int n){
            if(n == 1){ return true;}
            if(n % 3 != 0 || n <= 0){ return false;}
            return isPowerOfThree(n / 3);
        }
};

int main(){
    Solution s;
    cout << s.isPowerOfThree(27) << endl;
    cout << s.isPowerOfThree(0) << endl;
    cout << s.isPowerOfThree(9) << endl;
    cout << s.isPowerOfThree(45) << endl;
    return 0;
}