#include<bits/stdc++.h>

using namespace std;

//! O(Nlog(N)), 不找中位數
// 设 m 为中位数。a 和 b 是 m 两边的两个元素，
// 且 b > a。要使 a 和 b 相等，它们总共移动的次数为 b - a，
// 这个值等于 (b - m) + (m - a)，也就是把这两个数移动到中位数的移动次数
class Solution1 {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            moves += nums[h] - nums[l];
            l++;
            h--;
        }
        return moves;
    }
};

//! O(N), 先找中位數
class Solution2 {
public:
    int minMoves2(vector<int>& nums) {
        int moves = 0;
        //? Use quick select to find the median
        int median = findKthSmallest(nums, nums.size() / 2);
        for(int num : nums){
            moves += abs(num - median);
        }
        return moves;
    }

    int findKthSmallest(vector<int > &nums, int k){
        int l = 0, h = nums.size() - 1;
        while(l < h){
            int j = partition(nums, l, h);
            if(k == j){ break;}
            if(j < k){
                l = j + 1;
            }else{
                h = j - 1;
            }
        }
        return nums[k]; // median that I want
    }

    int partition(vector<int > &nums, int l, int h){
        int i = l, j = h + 1;
        while(1){
            while(i < h && nums[++i] < nums[l]){};
            while(j > l && nums[--j] > nums[l]){};
            if(i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};

int main(){
    Solution1 s;
    Solution2 s2;
    vector<int> nums = {1, 2, 3};
    vector<int> nums2 = {1, 10, 2, 9};
    cout << s2.minMoves2(nums) << endl;
    return 0;
}