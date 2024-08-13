#include<bits/stdc++.h>

using namespace std;

// [1 1 2 5 6 7 10]  target = 8

//! 使用回朔算法(Backtrack)
class Solution {
    vector<vector<int > > result;
    //紀錄回溯的路径
    vector<int> track;
    //紀錄 track 中的元素之和
    int trackSum = 0;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, 0, target);
        return result;
    }

    void backtrack(vector<int> &candidates, int start, int target){
        //base case，达到目标和，找到符合条件的组合
        if(trackSum == target){
            result.push_back(track);
            return;
        }
        //base case，超过目标和，直接结束
        if(trackSum > target){
            return;
        }

        //TODO Backtrack framework
        for(int i = start; i < candidates.size(); i++){
            //剪枝逻辑，值相同的树枝，只遍历第一条
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            //做选择
            track.push_back(candidates[i]);
            trackSum += candidates[i];
            //递归遍历下一层回溯树
            backtrack(candidates, i + 1, target);
            //撤销选择
            track.pop_back();
            trackSum -= candidates[i];
        }
    }
};

int main(){
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int> > result = s.combinationSum2(candidates, target);
    for(auto vec : result){
        for(auto num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}