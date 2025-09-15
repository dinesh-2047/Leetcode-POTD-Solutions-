// 1935. Maximum Number of Words You Can Type





// Approach 1 

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        vector<int> freq(26, 0);
        for (auto& b : brokenLetters) {
            freq[b - 'a']++;
        }

        int result = 0;
        bool broken = false;
        for (int i = 0; i < n; i++) {
            if (text[i] != ' ' && freq[text[i] - 'a']) {
                broken = true;

            } else if (text[i] == ' ') {
                if (!broken)
                    result++;

                broken = false;
            }
        }
        if (!broken)
            result++;

        return result;
    }
};










//Approach 2 

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        vector<int>freq(26, 0) ;
        for(auto &b : brokenLetters){
             freq[b -'a']++;
        }
        
        int result = 0 ; 
          int i = 0 ;
        for( i = 0 ; i  < n ; i++){
            if( text[i]!=' ' && freq[text[i] - 'a'] > 0){
                while( i  < n && text[i]!=' ') i++;

                if(i == n ) break; 
            }
            
           else if(text[i] == ' '){
              result++;
           }
           else if(i==n-1){
              result++;
           }

        }
      
        return result; 

       
    }
};











//Approach 3 
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        unordered_set<int>st; 
        for(auto &b : brokenLetters){
            st.insert(b);
        }
        
        int result = 0 ; 
          int i = 0 ;
        for( i = 0 ; i  < n ; i++){
            if(st.count(text[i])){
                while( i  < n && text[i]!=' ') i++;

                if(i == n ) break; 
            }
            
           else if(text[i] == ' '){
              result++;
           }
           else if(i==n-1){
              result++;
           }

        }
      
        return result; 

       
    }
};