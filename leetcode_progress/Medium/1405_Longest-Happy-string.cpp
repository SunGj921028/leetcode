#include<bits/stdc++.h>

using namespace std;

//! A greedy approach works well here because we can construct the string step by step by selecting the most available character,
//!  and if adding that character leads to three consecutive letters, we switch to the next most available character.

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        //? Use a max-heap (or priority queue) to keep track of the character counts.
        priority_queue<pair<int, char>> pq;
        if(a > 0){ pq.push({a, 'a'});}
        if(b > 0){ pq.push({b, 'b'});}
        if(c > 0){ pq.push({c, 'c'});}

        while(!pq.empty()){
            //* Get the character with the most count.
            int count1 = pq.top().first;
            char char1 = pq.top().second;
            pq.pop();

            // Check if the last two characters in result are the same.
            if(ans.size() >= 2 && ans.back() == char1 && ans[ans.size() - 2] == char1){
                if(pq.empty()){ break;}

                // Get the second most character.
                int count2 = pq.top().first;
                char char2 = pq.top().second;
                pq.pop();

                // Append the second most character to the result.
                ans += char2;
                count2--;
                // if the character is still left, add into pq with the new count
                if(count2 > 0){ pq.push({count2, char2});}

                // Push back the most frequent character for later use.
                pq.push({count1, char1});
            }else{
                // Append the most frequent character to the result.
                ans += char1;
                count1--;

                // if the character is still left, add into pq with the new count
                if(count1 > 0){ pq.push({count1, char1});}
            }
        }

        return ans;
    }
};

int main(){
    Solution* obj = new Solution();
    int a = 1, b = 1, c = 7;
    cout << obj->longestDiverseString(a, b, c) << "\n";
    return 0;
}