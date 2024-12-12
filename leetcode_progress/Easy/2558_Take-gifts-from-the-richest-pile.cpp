#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        for(int i = 0; i < k; i++){
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL); // 0LL is used to convert the result to long long
    }
};

int main(){
    Solution sol;
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    cout << sol.pickGifts(gifts, k) << endl;
    return 0;
}