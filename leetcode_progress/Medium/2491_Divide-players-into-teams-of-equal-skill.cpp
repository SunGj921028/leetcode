#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() % 2 != 0){ return -1;}
        long long chemistry = 0;
        sort(skill.begin(), skill.end());
        long sum = 0;
        for(int i = 0; i < skill.size() / 2; i++){
            long temp = skill[i] + skill[skill.size() - 1 - i];
            if(i != 0){
                if(sum != temp){ return -1;}
            }
            sum = temp;
            chemistry += (skill[i] * skill[skill.size() - 1 - i]);
        }
        return chemistry;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<int> skill = {3, 2, 5, 1, 3, 4};
    vector<int> skill2 = {3, 4};
    cout << obj->dividePlayers(skill2) << "\n";
    return 0;
}