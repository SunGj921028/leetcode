#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = nums[i] - 1; j >= 2; j--){
                if(i == 0 && isPrime(j)){
                    nums[i] -= j;
                    break;
                }
                if(isPrime(j) && nums[i] - j > nums[i - 1]){
                    nums[i] -= j;
                    break;
                }
            }
            if(i != 0 && nums[i] <= nums[i - 1]){ return false;}
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4, 9, 6, 10};
    vector<int> nums2 = {6, 8, 11, 12};
    vector<int> nums3 = {5, 8, 3};
    cout << s.primeSubOperation(nums) << endl;
    cout << s.primeSubOperation(nums2) << endl;
    cout << s.primeSubOperation(nums3) << endl;
    return 0;
}