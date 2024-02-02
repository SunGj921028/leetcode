#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
    public: 
        void reverseString(vector<char > &s){
            int n = s.size();
            for(int i = 0; i < n / 2 ;i++){
                swap(s[i], s[n - i - 1]);
            }
        }
};

class Solution2 {
    public: 
        void reverseString(vector<char> &s){
            int slow = 0, fast = s.size() - 1;
            while(slow < fast){
                char temp = s[slow];
                s[slow] = s[fast];
                s[fast] = temp;
                slow++;
                fast--;
            }
        }
};