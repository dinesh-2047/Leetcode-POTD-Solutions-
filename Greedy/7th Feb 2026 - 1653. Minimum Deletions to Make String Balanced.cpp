// 1653. Minimum Deletions to Make String Balanced


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int result = 0 ; 
        int countb = 0; 

        for(int i = 0 ; i  < n ;i++){
            if(s[i] == 'b') countb++;
            else if(s[i] == 'a'  ){
                if(countb == 0) continue; 
                else {
                    result++;
                    countb--;
                }
            }

        }
        return result; 
    }
};