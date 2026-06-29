// 1967. Number of Strings That Appear as Substrings in Word


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0 ; 
        for(auto &p : patterns){
            if(word.find(p)!=string::npos) result++;
        }
        return result; 
    }
};