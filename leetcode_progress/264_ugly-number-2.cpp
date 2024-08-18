#include<bits/stdc++.h>

using namespace std;

//! 对于这道题，我们抽象出三条有序的丑数链表，合并这三条有序链表得到的结果就是丑数序列，其中第 n 个丑数就是题目想要的答案

class Solution {
public:
    int nthUglyNumber(int n) {
        // 可以理解为三个指向有序链表头结点的指针
        int p2 = 1, p3 = 1, p5 = 1;
        // 可以理解为三个有序链表的头节点的值
        int product2 = 1, product3 = 1, product5 = 1;
        // 可以理解为最终合并的有序链表（结果链表）
        vector<int> ugly(n + 1);
        // 可以理解为结果链表上的指针
        int p = 1;

        // 开始合并三个有序链表，找到第 n 个丑数时结束
        while(p <= n){
            //? 取三個中最小的數
            int minVal = min({product2, product3, product5});
            ugly[p++] = minVal;
            
            //? 前進對應鏈表的指針
            if(minVal == product2){
                product2 = 2 * ugly[p2++];
            }
            if(minVal == product3){
                product3 = 3 * ugly[p3++];
            }
            if(minVal == product5){
                product5 = 5 * ugly[p5++];
            }
        }
        return ugly[n];
    }
};

int main(){
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    return 0;
}