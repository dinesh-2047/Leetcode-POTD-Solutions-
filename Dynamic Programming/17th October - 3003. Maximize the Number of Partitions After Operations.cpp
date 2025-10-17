// 3003. Maximize the Number of Partitions After Operations


// Approach 1 
class Solution {
public:
int n ; 
int solve(string &s, int &k ,  int i , long long uniqueChars , bool canChange){
    if(i >= n ) return 0;

    int charIdx = s[i] - 'a';
    int uniqueCharsUpdated = uniqueChars | (1 << charIdx);
    int uniqueCharCount = __builtin_popcount(uniqueCharsUpdated) ;

    int result ; 
    if(uniqueCharCount > k){
        result = 1 + solve(s, k ,i + 1, 1 << charIdx , canChange);

    }
    else{
        result = solve(s, k , i + 1, uniqueCharsUpdated, canChange);
    }

    if(canChange){
        for(int newCharIdx = 0 ; newCharIdx < 26; newCharIdx++){
            int newSet = uniqueChars | (1 << newCharIdx);
            int newUniqueCharCount = __builtin_popcount(newSet);

            if(newUniqueCharCount > k ){
                result = max(result , 1 + solve(s, k , i + 1, 1 << newCharIdx, false));

            }
            else{
                result = max(result , solve(s, k , i + 1, newSet,false));
            }
        }
    }
    return result; 
}
    int maxPartitionsAfterOperations(string s, int k) {
        n = s.length();

        return solve(s, k , 0 , 0 , true) +1;
    }
};


//Approach 2 
class Solution {
public:
int n ; 
unordered_map<long long , int>mp ; 
int solve(string &s, int &k ,  long long i , long long uniqueChars , bool canChange){
    long long key = ( i << 27 ) | (uniqueChars << 1) | (canChange);

    if(mp.count(key)) return mp[key];

    if(i >= n ) return 0;

    int charIdx = s[i] - 'a';
    int uniqueCharsUpdated = uniqueChars | (1 << charIdx);
    int uniqueCharCount = __builtin_popcount(uniqueCharsUpdated) ;

    int result ; 
    if(uniqueCharCount > k){
        result = 1 + solve(s, k ,i + 1, 1 << charIdx , canChange);

    }
    else{
        result = solve(s, k , i + 1, uniqueCharsUpdated, canChange);
    }

    if(canChange){
        for(int newCharIdx = 0 ; newCharIdx < 26; newCharIdx++){
            int newSet = uniqueChars | (1 << newCharIdx);
            int newUniqueCharCount = __builtin_popcount(newSet);

            if(newUniqueCharCount > k ){
                result = max(result , 1 + solve(s, k , i + 1, 1 << newCharIdx, false));

            }
            else{
                result = max(result , solve(s, k , i + 1, newSet,false));
            }
        }
    }
    return mp[key] = result; 
}
    int maxPartitionsAfterOperations(string s, int k) {
        n = s.length();

        return solve(s, k , 0 , 0 , true) +1;
    }
};