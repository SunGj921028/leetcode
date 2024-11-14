#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<int>&quantities, int mid){
        int stores = 0;
        for(auto x : quantities){
            stores += x / mid;
            if(x % mid) stores++;  
            if(stores > n) return 0;
        }
        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1, e = *max_element(quantities.begin(),quantities.end()), ans = -1;
        while(s <= e){
            int mid = s + ( e - s ) / 2;
            if(isPossible(n, quantities, mid)){
                ans = mid;
                e = mid - 1; //! Left side
            }else{
                s = mid + 1; //! Right side
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    int n = 6;
    vector<int> quantities = {11, 6};
    cout << solution.minimizedMaximum(n, quantities) << endl;
    return 0;
}