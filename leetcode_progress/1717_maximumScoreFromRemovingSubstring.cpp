#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
    public:
        int maximumGain(string s, int x, int y){
            char key[] = "ab";
            if(y > x){
                key[0] = 'b';
                key[1] = 'a';
            }
            int high = max(x, y);
            int low = min(x, y);

            //! Greedy for high score
            int score = 0;
            stack<char> leftStack;
            for(auto i : s){
                char c = i;
                if( leftStack.empty() || (c != key[0] && c != key[1])){
                    leftStack.push(c);
                    continue;
                }

                //? When meet the high score pattern
                if( c == key[1] && leftStack.top() == key[0]){
                    leftStack.pop();
                    score += high;
                    continue;
                }
                leftStack.push(c);
            }

            //! Greedy for low score
            stack<char> rightStack;
            while(!leftStack.empty()){
                char c = leftStack.top();
                leftStack.pop();
                if(rightStack.empty() || (c != key[0] && c != key[1])){
                    rightStack.push(c);
                    continue;
                }

                //? When meet the low score pattern
                if(c == key[1] && rightStack.top() == key[0]){
                    rightStack.pop();
                    score += low;
                    continue;
                }
                rightStack.push(c);
            }
            return score;
        }
};

class Solution2 {
    public: 
        int maximumGain(string s, int x, int y){
            //! Ensure "ab" always has the higher score
            if(x < y){
                //* Swap x and y
                x = x ^ y;
                y = x ^ y;
                x = x ^ y;
                //* Reverse s to maintain the logic
                reverse(s.begin(), s.end());
            }

            int aCount = 0, bCount = 0, score = 0;
            for(auto i : s){
                char c = i;
                if(c == 'a'){
                    ++aCount;
                }else if(c == 'b'){
                    if(aCount > 0){
                        //! Form "ab"
                        --aCount;
                        score += x;
                    }else {
                        //! Keep "b" for potential "ba"
                        ++bCount;
                    }
                }else {
                    //! Non "a" or "b"
                    //? Calculate scores for any "ba" pairs
                    score += min(aCount, bCount) * y;
                    aCount = 0;
                    bCount = 0;
                }
            }
            //? Calculate scores for any remaining "ba" pairs
            score += min(aCount, bCount) * y;
            return score;
        }
};