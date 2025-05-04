// 1128. Number of Equivalent Domino Pairs
/*
💎 Approach 1: Brute Force
 🔹 Compare every possible pair using two nested loops.
 🔹 Check both [a, b] == [c, d] and [a, b] == [d, c].
 🔹 Time complexity: O(n²) — not efficient for large inputs.

💎 Approach 2: Map with vector<int> Key
 🔹 For each domino, check if it or its reverse is already in the map.
 🔹 Use a map with vector keys and update counts accordingly.
 🔹 Reduces comparisons but still involves overhead due to vector lookups.

💎 Approach 3: Unordered Map with string Key
 🔹 Convert each domino to a string (e.g., "12" or "21").
 🔹 Normalize the string to sorted order for consistency.
 🔹 Use a hash map to count equivalent strings.

💎 Approach 4: Optimized Frequency Array ✅
 🔹 Always store dominoes in sorted order: (min, max).
 🔹 Convert to a unique number: key = a * 10 + b.
 🔹 Maintain a frequency array arr[100] to count appearances.
 🔹 Add arr[key] to total count before incrementing it. */

// Approach 1 
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
                int n = dominoes.size();
               int count = 0 ; 
    
            for(int i= 0 ; i<n-1; i++){
                int a = dominoes[i][0];
                int b = dominoes[i][1];
                for(int j = i + 1; j < n;  j++){
                    int c = dominoes[j][0];
                    int d = dominoes[j][1];
    
                    if((a==c && b==d) || (a==d && b==c)) count++;
                }
            }
            return count;         
        }
    };



//Approach 2 
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int n = dominoes.size();
    
          map<vector<int>, int>mp ;
          int count = 0 ; 
           for(auto &v : dominoes){
               if(mp.find(v) != mp.end()) {
                        count += mp[v];
               }
               else {
                swap(v[0], v[1]);
                if(mp.find(v)!=mp.end()) count+=mp[v];
               }
               mp[v]++;
    
               
    
           }
          return count; 
        }
    };




//Approach 3 
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int n = dominoes.size();
    
          unordered_map<string, int>mp ;
          int count = 0 ; 
           for(auto &v : dominoes){
            char ch1 = v[0] + '0';
            char ch2 = v[1] + '0';
            string str = "";
            str.push_back(ch1);
            str.push_back(ch2);
               if(mp.find(str) != mp.end()) {
                        count += mp[str];
               }
               else {
                swap(str[0], str[1]);
                if(mp.find(str)!=mp.end()) count+=mp[str];
               }
               mp[str]++;
    
               
    
           }
          return count; 
        }
    };




//Approach 4 
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int n = dominoes.size();
    
            vector<int>arr(100,0);
            int count = 0 ; 
    
            for(auto &v :dominoes){
                 if(v[0] > v[1]) swap(v[0], v[1]);
                 int num = (v[0] * 10 + v[1]);
                   
                   count += arr[num];
    
                   arr[num]++;
                 
    
            }
            return count; 
        }
    };