#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int maxDepth(string s){
            int max_depth = 0, depth = 0;
            for(auto &it:s){
                if(it == '('){
                    depth++;
                    max_depth = max(max_depth, depth);
                }else if(it == ')'){
                    depth--;
                }
            }
            return max_depth;
        }
};