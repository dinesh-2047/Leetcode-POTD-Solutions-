// 1957. Delete Characters to Make Fancy String




// Approach 1 
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result =  "";
        
        for(int i = 0 ; i <n; i++){
            if(s[i] == s[i +1 ] && s[i + 1] == s[i + 2]){
                continue; 
            }
            else result.push_back(s[i]);
        }
        return result; 
    }
};








//Approach 2 
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result =  "";
         result.push_back(s[0]);
            
          int charCount = 1 ; 
         for(int i = 1 ;i <n; i++){
             if(s[i] == result.back()){
                 charCount++;
                 if(charCount < 3) result.push_back(s[i]);
             }
             else {
                charCount = 1; 
                result.push_back(s[i]);

             }
         }
         return result; 
    }
};