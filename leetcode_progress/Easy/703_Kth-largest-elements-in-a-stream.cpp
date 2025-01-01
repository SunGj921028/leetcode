#include<bits/stdc++.h>

using namespace std;

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
private:
    int k;
    // 默认是小顶堆
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        // 将 nums 装入小顶堆，保留下前 k 大的元素
        for(int e : nums){
            pq.push(e);
            if(pq.size() > k){
                pq.pop();
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}