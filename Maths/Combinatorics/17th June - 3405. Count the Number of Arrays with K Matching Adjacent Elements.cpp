// 3405. Count the Number of Arrays with K Matching Adjacent Elements
/*
✨ LeetCode POTD: Count the Number of Arrays with K Matching Adjacent Elements (3405) 🔢📊

⁉️ Problem Statement:
🔸 You are given three integers: n, m, and k.
🔸 A good array of length n contains integers in the range [1, m] and has exactly k positions i (1 ≤ i < n) where arr[i] == arr[i–1].
🔸 Return the number of such good arrays, modulo 10⁹ + 7.

🔎 Approach Used: Combinatorics + Fast Modular Arithmetic

🔹 Choose k adjacent positions (out of n–1) where elements will be the same. This can be done in C(n–1, k) ways using combinatorics.
🔹 These k positions create exactly n–k groups of values.
  • First group can take any of the m values.
  • Each next group must differ from the previous, so each has m–1 choices.
🔹 Total number of such arrays = C(n–1, k) × m × (m–1)^(n–k–1) modulo 1e9+7.
🔹 To compute efficiently:
  • Precompute factorials up to n.
  • Use Fermat’s Little Theorem to calculate modular inverses for nCr.
  • Apply fast binary exponentiation to compute (m–1)^(n–k–1) efficiently.
*/












class Solution {
public:
int mod = 1e9 + 7;
int findPower(int a , int b){
    if(b==0) return 1; 
    long long half = findPower(a, b/2)%mod;
    long long result = (half * half)%mod; 

    if(b%2==1){
        result = (result *a)%mod; 
    }
    return result; 
}


int nCr(int n , int r, vector<long long> &fact){
    long long ncr = fact[n];
    ncr = ncr * findPower(fact[n-r], mod-2) %mod; 
    ncr = ncr * findPower(fact[r], mod-2 )%mod; 

    return (int) ncr ; 
}

    int countGoodArrays(int n, int m, int k) {
        vector<long long>fact(n+1);

        fact[0] = fact[1] = 1; 

        for(int i = 2 ; i <= n ; i++){
            fact[i]  = (fact[i-1] * i )%mod; 
        }

        long long result = nCr(n-1, k , fact);
        result = (result * m %mod* findPower(m-1, n-1-k)%mod)%mod; 

        return (int) result; 
    }
};