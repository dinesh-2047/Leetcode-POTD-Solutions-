// 3337. Total Characters in String After Transformations II

/*
✨ Today's LeetCode POTD: Total Characters in String After Transformations II (3337) 🚀

⁉️ Problem Statement:
You're given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".

The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into "zab".

Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 10⁹ + 7.

🔷 Approaches I Used:

💎 Approach: Matrix Exponentiation for Efficient Transformation

🔹 Transformation Matrix Construction:
Construct a 26x26 matrix T where T[i][j] indicates how many times character 'a'+i contributes to 'a'+j after one transformation.
For each character 'a'+i, we increment T[(i + k) % 26][i]++ for each k from 1 to nums[i].

🔹 Matrix Exponentiation:
Since applying the transformation t times is equivalent to raising the transformation matrix T to the power t, we use fast matrix exponentiation to compute T^t efficiently.

🔹 Initial Frequency Vector:
Build a frequency vector freq of size 26 where freq[i] is the count of character 'a'+i in the original string s.

🔹 Final Frequency Calculation:
Multiply the frequency vector freq with the exponentiated matrix T^t to get the final frequency vector after all transformations.

🔹 Result Computation:
Sum all elements of the final frequency vector to get the total number of characters in the transformed string.

💻 Language: C++
📌 Concepts Used: Matrix Exponentiation, Modular Arithmetic, Frequency Mapping
📈 Time Complexity: O(log t × 26³)
📦 Space Complexity: O(26²)

*/


//Approach - Using Matrix Exponentiation
//T.C : O(n + log(t))
//S.C : O(26*26) ~ O(1)
class Solution {
public:
const int mod  = 1e9 + 7;
typedef vector<vector<int>> Matrix;

Matrix matrixMultiplication(Matrix &a, Matrix &b){
    Matrix C(26, vector<int>(26,0));

    for(int i = 0 ; i<26; i++){
        for(int j = 0; j< 26; j++){
            for(int k = 0; k < 26; k++){
                C[i][j] = (C[i][j] +(1LL * a[i][k] * b[k][j])%mod )% mod;
            }
        }
    }
    return  C;
}


Matrix matrixExponentiation(Matrix &base , int exponent ){
    if(exponent == 0 ) {
        Matrix I(26, vector<int>(26,0));
        for(int i = 0 ; i<26; i++){
            I[i][i] = 1;
        }
        return I;
    }

    Matrix half = matrixExponentiation(base , exponent/2);
    Matrix result = matrixMultiplication(half , half);
    if(exponent % 2==1){
         result = matrixMultiplication(result, base);
    }

    return result; 
}


    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int>freq(26,0);

        for(char &ch : s){
            freq[ch -'a']++;
        }
         Matrix T (26, vector<int> (26,0));

        for(int i = 0 ; i<26; i++){
            for(int add = 1; add <= nums[i]; add++){
                T[(i+add)%26][i]++;
            }
        }
        Matrix result = matrixExponentiation(T,t);

        vector<int>updated_freq(26,0);

        for(int i = 0 ; i<26; i++){
            for(int j = 0 ; j<26; j++){
                updated_freq[i] = (updated_freq[i] + ((long long)result[i][j] * freq[j])%mod)%mod; 
            }
        }

        int resultlen = 0 ; 
        for(int i = 0 ; i<26; i++){
            resultlen = (resultlen + updated_freq[i])%mod; 
        }
        return resultlen;
    }
};
