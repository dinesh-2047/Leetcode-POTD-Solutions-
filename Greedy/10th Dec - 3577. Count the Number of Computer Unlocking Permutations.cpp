// 3577. Count the Number of Computer Unlocking Permutations


class Solution {
public:
int mod = 1e9 + 7; 
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        long long result = 1; 
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]) return 0 ; 
            result = (result * i)%mod; 
        }
        return result; 
    }
};