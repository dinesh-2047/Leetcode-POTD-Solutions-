// 3335. Total Characters in String After Transformations I

/*
🔍 Problem Statement:
You're given a lowercase string s and an integer t. In each transformation, every character 'z' turns into "ab" and every other character 'c' becomes the next character 'd'. After performing this transformation t times, return the total number of characters in the resulting string. Since the answer may be large, return it modulo 10⁹+7.

🔷 Approaches I Used:

💎 Approach: Frequency Mapping & Simulation
🔹 Maintain a frequency array mp[26] to count the occurrence of each character.
🔹 Perform t transformations:
    🔹 For 'z', add its count to 'a' and 'b'.
    🔹 For other characters, shift their frequency to the next character.
🔹 Use a temporary array temp during each iteration to avoid in-place issues.
🔹 After all transformations, sum all frequencies to get the total character count.

💻 Language: C++
📌 Concepts Used: Arrays, Frequency Count, Simulation, Modulo Arithmetic
📈 Time Complexity: O(t × 26)
📦 Space Complexity: O(26)



*/

class Solution {
public:
const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
       vector<int>mp(26,0);


         for(int i = 0 ; i<s.length(); i++){
            mp[s[i]-'a']++;
         }

         while(t--){
            vector<int>temp(26,0) ; 
            for(int i = 0 ; i<26; i++){
               char ch = i + 'a' ; 
               int freq = mp[i]; 

               if(ch == 'z'){
                  temp['a'-'a'] = (temp['a'-'a'] + freq)%mod; 
                  temp['b'-'a'] = (temp['b'-'a'] + freq)%mod;
               }

               else{
                  temp[(ch + 1)-'a'] = (temp[(ch+1)-'a'] + freq) %mod; 
               }
            }
            mp = move(temp);
         }
         int result = 0 ; 
         for(auto &freq : mp){
           result = (result + freq)%mod; 
         }
         return result %mod; 
    }
};