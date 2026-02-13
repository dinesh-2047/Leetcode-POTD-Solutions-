// 3714. Longest Balanced Substring II



class Solution {
public:
int n ; 
int case2(string &s, char ch1 , char ch2){
   unordered_map<int, int>mp;  
   int max_len = 0 ; 
    mp[0] = -1; 

    int count1 = 0 ; 
    int count2 = 0 ; 

    for(int i = 0 ; i  < n ; i++){
          if(s[i] != ch1 && s[i] != ch2){
             count1 = 0 ; 
             count2 = 0 ;
             mp.clear();
             mp[0] = i; 
             continue; 
          }
          if(s[i] == ch1) count1++;
          else count2++;

          int diff = count1 - count2 ; 
          if(mp.count(diff)){
             max_len = max(max_len, i - mp[diff]);
          }
          else 
          mp[diff] = i ; 
    }


    return max_len;
}
    int longestBalanced(string s) {
         n = s.length();

        int result = 1 ; 

        //case 1 only 1 char substring 
        int count = 1 ; 
        for(int i = 1; i  < n ; i++ ){
            if(s[i] == s[i - 1] ) {
                 count++;
            }
            else {
                count = 1; 
            }
            result = max(result , count);
        }

        // case 2 two char substring 
        vector<pair<char, char>>vec = {{'a', 'b'}, {'b', 'c'}, {'a','c'}};

        for(int i = 0 ; i  < 3; i++){
            auto [ch1, ch2] = vec[i];
            result = max(result, case2(s, ch1, ch2));
        }


        // case 3 three char substring 
        int count1 = 0 ; 
        int count2 = 0 ; 
        int count3 = 0 ; 

        unordered_map<string , int>mp;
        mp["0_0"] = -1; 
        for(int i = 0 ; i  < n; i++){
            if(s[i] == 'a' ) count1++;
            else if(s[i] == 'b') count2++;
            else count3++;

            int diff1 = count1 - count2; 
            int diff2 = count2 - count3 ; 

            string key = to_string(diff1) + "_" + to_string(diff2);
            if(mp.count(key)){
                result = max(result, i - mp[key]);
            }
            else 
            mp[key] = i; 
        }

        return result; 


    }
};