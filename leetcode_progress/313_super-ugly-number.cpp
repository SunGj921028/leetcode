#include<bits/stdc++.h>

using namespace std;

//! Combine number len(primes) of list

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> pointers(len, 1);
        vector<long> value(len, 1);

        vector<long> ugly(n + 1);
        int p = 1;

        while(p <= n){
            //! Find the minimum value of the list node
            int minValue = INT_MAX;
            for(auto val : value){
                if(val < minValue){
                    minValue = val;
                }
            }
            ugly[p++] = minValue;

            for(int i = 0;i < len; i++){
                if(minValue == value[i]){
                    value[i] = primes[i] * ugly[pointers[i]++]; //! Might overflow, so use <long>
                }
            }
        }
        return ugly[n];
    }
};

int main(){
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    vector<int> primes2 = {2, 3, 5};
    cout << s.nthSuperUglyNumber(12, primes) << endl;
    return 0;
}