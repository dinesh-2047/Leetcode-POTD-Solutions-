// 3330. Find the Original Typed String I


class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();

        int result = 1; 
        int prev = word[0];

        for(int i = 1 ; i < n; i++){
            if(word[i] == prev) result++;
            prev = word[i];
        }

        return result; 
    }
};