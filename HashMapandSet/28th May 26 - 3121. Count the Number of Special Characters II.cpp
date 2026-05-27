// 3121. Count the Number of Special Characters II


class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> last_small(26, -1); 
        vector<int> first_cap(26, -1);
        for(int i= 0 ; i < n; i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                last_small[word[i] -'a'] = i; 
            }
        }
        for(int i=  n- 1 ; i  >= 0 ; i--){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                first_cap[word[i] -'A'] = i; 
            }
        }
         int result = 0 ; 
        for(int i = 0 ; i  < 26; i++){
            if(last_small[i] == -1 || first_cap[i] == -1) continue; 
                
            if(last_small[i] < first_cap[i]){
                result++;
            }


        }
      
        return result; 
    }
};