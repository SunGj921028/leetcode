#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        string longestPalindrome(string s){
            string ans = "";
            for(int i = 0;i < s.length();i++){
                // 以 s[i] 为中心的最长回文子串, 奇数
                string s1 = palindrome(s, i, i);
                // 以 s[i] 和 s[i+1] 为中心的最长回文子串, 偶数
                string s2 = palindrome(s, i, i + 1);
                ans = ans.length() > s1.length() ? ans : s1;
                ans = ans.length() > s2.length() ? ans : s2;
            }
        }

        string palindrome(string s, int l, int r){
            // 防止索引越界
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                // 向两边展开
                l--;
                r++;
            }
            l++;
            // 返回以 s[l] 和 s[r] 为中心的最长回文串
            return s.substr(l, r - l);
        }
};

class Solution2 {
    public: 
        string longestPalindrome(string s){
            int n = s.size();
            vector<vector<int>> dp(n, vector<int>(n));
            string ans = "";
            for(int l = 0;l < n;l++){
                for(int i = 0;i + l < n;i++){
                    int j = i + l;
                    if(l == 0){
                        dp[i][j] = 1;
                    }else if(l == 1){
                        dp[i][j] = (s[i] == s[j]);
                    }else{
                        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                    }
                    if(dp[i][j] && l + 1 > ans.size()){
                        ans = s.substr(i, l + 1);
                    }
                }
            }
            return ans;
        }
};

class Solution3 {
    public: 
        string longestPalindrome(string s){
            if(s.length() <= 1){ return s;}
            int maxLen = 1;
            string maxStr = s.substr(0, 1);
            s = "#" + regex_replace(s, std::regex(""), "#") + "#";
            vector<int> dp(s.length(), 0);
            int center = 0, right = 0;

            for (int i = 0; i < s.length(); ++i) {
                if (i < right) {
                    dp[i] = min(right - i, dp[2 * center - i]);
                }
                
                while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
                    dp[i]++;
                }
                
                if (i + dp[i] > right) {
                    center = i;
                    right = i + dp[i];
                }
                
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                    maxStr.erase(remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
                }
            }
            return maxStr;
        }
};