// 3016. Minimum Number of Pushes to Type Word II




class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int , char>> freq(26, {0, '*'});
        for(auto &ch : word){
           freq[ch - 'a'] = { ++freq[ch - 'a'].first,  ch};
        }
        
        sort(rbegin(freq), rend(freq));
        int cnt = 0 ; 
        int press = 1; 

        vector<int> tap(26, 0);

        for(int i = 0 ; i  < 26; i++){
            if(cnt == 8) {
                press++;
                cnt = 0 ;
            }
            if(freq[i].first  >  0){
                cnt++;
                tap[freq[i].second - 'a'] = press; 
            }
        }
        
        int result = 0; 
        for(int i= 0 ; i < 26; i++){
            if(freq[i].first > 0){
                result += (freq[i].first * tap[freq[i].second - 'a']);
            }
        }
        return result;

    }
};