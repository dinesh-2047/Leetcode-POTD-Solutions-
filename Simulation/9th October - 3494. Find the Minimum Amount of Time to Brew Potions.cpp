// 3494. Find the Minimum Amount of Time to Brew Potions


class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        
        vector<long long>ft(n, 0);
        for(int i = 0 ; i < m ; i++){
            
            ft[0] += 1LL * skill[0] * mana[i];
            for(int j = 1 ; j < n; j++){
                ft[j] = max(ft[j], ft[j-1]) + 1LL * mana[i] * skill[j];
            }
            for(int j = n-1; j > 0; j--){
                ft[j-1] = ft[j] -1LL *  mana[i] * skill[j];
            }
        }
        return ft[n-1];
    }
};