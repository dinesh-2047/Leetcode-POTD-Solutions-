// 1358. Number of Substrings Containing All Three Characters/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int count_a = 0 ; 
        int count_b = 0 ; 
        int count_c = 0 ; 

        int i = 0 ; 
        int j = 0 ; 
        int result = 0 ; 

        while(j < n ){
            if(s[j] == 'a') count_a++;
            else if(s[j] == 'b') count_b++;
            else count_c++;

            while(i < j && count_a > 0 && count_b > 0 && count_c > 0 ){
                result += (n - j );

                if(s[i] == 'a') count_a--;
                else if(s[i] == 'b') count_b--;
                else count_c--;
                i++;
            }
            j++;
        }
        return result; 
    }
};