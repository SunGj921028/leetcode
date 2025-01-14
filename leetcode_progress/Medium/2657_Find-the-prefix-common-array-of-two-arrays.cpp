#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result(A.size(), 0);
        unordered_map<int, int> freq;
        int commonCount = 0;
        for(int i = 0; i < A.size(); i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2){ commonCount++; }
            freq[B[i]]++;
            if(freq[B[i]] == 2){ commonCount++; }

            result[i] = commonCount;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    vector<int> result = s.findThePrefixCommonArray(A, B);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}