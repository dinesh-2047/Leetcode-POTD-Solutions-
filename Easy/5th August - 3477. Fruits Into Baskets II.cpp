// 3477. Fruits Into Baskets II


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<bool>placed(n, false);

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ;j < n; j++){
                if(baskets[j] >= fruits[i] && !placed[j] ){
                    placed[j] = true; 
                    break; 
                }
            }
        }
        int count = 0 ; 
        for(int i = 0 ; i <n;i++){
            if(!placed[i]) count++;
        }
        return count; 
    }
};