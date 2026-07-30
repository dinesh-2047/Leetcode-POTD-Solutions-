// 3014. Minimum Number of Pushes to Type Word I

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto &ch : word){
            freq[ch - 'a']++;
        }

        int cnt = 0 ; 
        int press = 1; 

        vector<int> tap(26, 0);

        for(int i = 0 ; i  < 26; i++){
            if(cnt == 8) {
                press++;
                cnt = 0 ;
            }
            if(freq[i]  >  0){
                cnt++;
                tap[i] = press; 
            }
        }
        
        int result = 0; 
        for(int i= 0 ; i < 26; i++){
            if(freq[i] > 0){
                result += (freq[i] * tap[i]);
            }
        }
        return result;

    }
};