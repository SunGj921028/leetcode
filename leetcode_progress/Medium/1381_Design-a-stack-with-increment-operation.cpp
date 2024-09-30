#include<bits/stdc++.h>

using namespace std;

class CustomStack {
public:
    vector<int > stk;
    int top;
    int maxSizeOfStack;
    CustomStack(int maxSize) {
        stk = vector<int > (maxSize, -1);
        top = -1;
        maxSizeOfStack = maxSize;
    }
    
    void push(int x) {
        if(top == (maxSizeOfStack - 1)){ return;}
        stk[++top] = x;
        return;
    }
    
    int pop() {
        if(top == -1){ return -1;}
        return stk[top--];
    }
    
    void increment(int k, int val) {
        if(k > maxSizeOfStack){ k = maxSizeOfStack;}
        for(int i = 0;i < k; i++){
            stk[i] += val;
        }
        return;
    }
};

int main(){
    CustomStack* obj = new CustomStack(3);
    int output = 0;
    obj->push(1);
    obj->push(2);
    output = obj->pop();
    cout << output << "\n";
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->increment(5, 100);
    obj->increment(2, 100);
    output = obj->pop();
    cout << output << "\n";
    output = obj->pop();
    cout << output << "\n";
    output = obj->pop();
    cout << output << "\n";
    output = obj->pop();
    cout << output << "\n";
    return 0;
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */