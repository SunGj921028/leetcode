#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        // Initialize the result sequence with size 2*n - 1 filled with 0s
        vector<int> resultSequence(targetNumber * 2 - 1, 0);

        // Keep track of which numbers are already placed in the sequence
        vector<bool> isNumberUsed(targetNumber + 1, false);

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed,
                                            targetNumber);

        return resultSequence;
    }

    bool findLexicographicallyLargestSequence(int currIndex, vector<int>& resultSequence, vector<bool>& isNumUsed, int targetNum){
        // If we have filled all positions, return true indicating success
        if (currIndex == resultSequence.size()) {
            return true;
        }

        // If the current position is already filled, move to the next index
        if(resultSequence[currIndex] != 0){
            return findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumUsed, targetNum);
        }

        // Attempt to place numbers from targetNumber to 1 for a
        // lexicographically largest result
        for(int n = targetNum; n >= 1; n--){
            if(isNumUsed[n]){ continue; }

            isNumUsed[n] = true;
            resultSequence[currIndex] = n;

            if(n == 1){
                if(findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumUsed, targetNum)){ return true; }
            }else if(currIndex + n < resultSequence.size() && resultSequence[currIndex + n] == 0) {
                resultSequence[currIndex + n] = n;
                if(findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumUsed, targetNum)){ return true; }

                //! If not valid for currIndex + n, backtracking
                resultSequence[currIndex + n] = 0;
            }

            //! If not valid for currIndex, backtracking
            isNumUsed[n] = false;
            resultSequence[currIndex] = 0;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> res = s.constructDistancedSequence(3);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}