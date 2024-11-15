#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int idxPrefix = 0, idxSuffix = arr.size() - 1;
        int n = arr.size();
        //! For prefix
        for(; idxPrefix + 1 < n && arr[idxPrefix] <= arr[idxPrefix + 1]; idxPrefix++);
        // array is already non-decreasing
        if (idxPrefix == n - 1) return 0;
        //! For suffix
        for(; idxSuffix > idxPrefix && arr[idxSuffix - 1] <= arr[idxSuffix]; idxSuffix--);

        // to remove as the smaller of removing all from either end
        int remove = min(n - idxPrefix - 1, idxSuffix);
        // Try to merge left and right parts
        for (int i = 0, j = idxSuffix; i <= idxPrefix && j < n; ) {
            if (arr[i] <= arr[j]) {
                //  remove elements  with index in (i, j)
                remove = min(remove, j - i - 1);
                i++;
            } else { j++; }  
        }
        return remove;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    vector<int> arr2 = {5, 4, 3, 2, 1};
    vector<int> arr3 = {1, 2, 3};
    cout << solution.findLengthOfShortestSubarray(arr) << endl;
    cout << solution.findLengthOfShortestSubarray(arr2) << endl;
    cout << solution.findLengthOfShortestSubarray(arr3) << endl;
    return 0;
}