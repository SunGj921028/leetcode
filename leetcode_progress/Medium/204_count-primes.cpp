#include<bits/stdc++.h>

using namespace std;

//! Using algorithm Sieve of Eratosthenes
// 埃拉托斯特尼篩法通過不斷地標記當前質數的所有倍數為合數，從而取得最小的未標記整數為下一個質數。
// 尋找N以內的質數時，若找到了一個大於根號N的質數，則剩餘的所有尚未標記的數也都是質數。
// 標記某一質數p的倍數時，不需要每次皆從2p,3p,…開始，而可直接從p^2開始標記

//TODO Method 1 TLE...
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2){ return 0;}
        set<int> number;
        for(int i = 2 ; i < n; i++ ){ // Set for number 2 to N - 1
            number.insert(i);
        }

        for(auto i : number){
            if(i > sqrt(n)){ break;}
            int head = i * i;
            while(head <= n){
                number.erase(head);
                head += i;
            }
        }
        return number.size();
    }
};

//TODO Method 2
class Solution2 {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2){ return 0;}
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};

int main(){
    Solution s;
    cout << s.countPrimes(3) << endl;
    return 0;
}