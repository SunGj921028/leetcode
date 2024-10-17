#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int maximumSwap(int num) {
//         int ans = 0;
//         vector<int> digits;
//         while(num>0){
//             digits.push_back(num%10);
//             num /= 10;
//         }
//         int maxi=0;
//         vector<int> temp(digits.size());
//         temp[0] = -1; // 初始化，最左邊無法交換，所以設置為 -1
//         for(int i = 1;i < digits.size();i++){
//             temp[i] = digits[maxi] > digits[i] ? maxi : -1; // 如果當前數字比最大數字小，記住當前可以交換的索引
//             // 如果當前數字比已知最大數字大，更新最大數字的位置
//             if(digits[i] > digits[maxi]){
//                 maxi = i; 
//             }
//         }

//         for(int i = temp.size() - 1; i >= 0; i--){
//             if(temp[i] != -1){
//                 swap(digits[i], digits[temp[i]]);
//                 break;
//             }
//         }

//         int mul = pow(10, temp.size() - 1);
//         int origin = 0;
//         for(int i = digits.size() - 1; i >= 0; i--){
//             origin += (digits[i] * mul);
//             mul /= 10;
//         }
//         return origin;
//     }
// };

class Solution{
public:
    int maximumSwap(int num){
        string numStr = to_string(num);
        vector<int> last(10, -1); // 0-9
        for(int i = 0; i < numStr.size(); i++){
            last[numStr[i] - '0'] = i; // -1 -1 0 2 -1 -1 3 1 -1 -1
        }

        for(int i = 0; i < numStr.size(); i++){
            for(int d = 9; d > (numStr[i] - '0'); d--){
                if(last[d] > i){
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};

int main(){
    Solution* obj = new Solution();
    int num = 2736;
    int num1 = 9973;
    cout << obj->maximumSwap(num) << "\n";
    cout << obj->maximumSwap(num1) << "\n";
    return 0;
}