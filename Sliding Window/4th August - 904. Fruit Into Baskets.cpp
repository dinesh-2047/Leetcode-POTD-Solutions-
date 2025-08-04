// 904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int , int>mp ; 
        int result = 0; 
        int i =  0 ; 
        int j = 0 ; 
        int count = 0  ;

        while(j < n ){
            mp[fruits[j]]++;
            if(mp.size() >2 ){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        return result; 
    }
};