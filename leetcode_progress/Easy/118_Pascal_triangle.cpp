#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
            ret.push_back(row);
	    }
	    return ret;
    }
};

int main() {
    Solution solution;
    int numRows = 5;
    vector<vector<int>> ret = solution.generate(numRows);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}