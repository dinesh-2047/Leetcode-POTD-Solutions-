// 3304. Find the K-th Character in String Game I





// Approach 1  -> simulation 
class Solution {
public:
    char kthCharacter(int k) {
        string s= "a";
         
        
        while(s.length()<k){
           string next = "";
           for(int i = 0 ; i <s.length() ;i++){
                if(s[i] == 'z'){
                    next.push_back('a');
                }

                char newCh  = s[i] + 1;
                next.push_back(newCh);

           }
           s = s + next; 
        }

        return s[k-1];
    }
};







//Approach2 -> Maths 
class Solution {
public:
    char kthCharacter(int k) {
        int cnt = __builtin_popcount(k-1);
        return 'a' + cnt;
    }
};