// 2014. Longest Subsequence Repeated k Times


/*
✨ LeetCode POTD: Longest Subsequence Repeated k Times (2014) 🔁🧩

⁉️ Problem Statement (LeetCode):
🔸 You are given a string s and an integer k.
🔸 Your task is to find the longest subsequence such that when repeated k times, it still remains a subsequence of s.
🔸 If multiple such subsequences exist, return the lexicographically largest one.
🔸 If none exists, return an empty string.

🔎 Approach I Used (C++):

▶️ 1. BFS (Breadth-First Search) + Frequency-Based Pruning
🔹 Count the frequency of each character in s. Only characters appearing at least k times are considered as potential candidates, reducing the search space.
🔹 Use a BFS traversal starting from all single-character strings formed from those candidates.
🔹 For every current subsequence in the queue, generate new subsequences by appending one more valid character from the candidate list and check whether the new sequence repeated k times is a subsequence of the original string s.
🔹 A helper function isKRepeated is used to verify if curr × k is a valid subsequence.
🔹 Among all valid subsequences, maintain the longest and in case of a tie, the lexicographically largest one.

▶️ 2. Backtracking + Lexicographical Ordering + Frequency Constraint
🔹 Similar to BFS, first extract characters that appear at least k times. Then compute the maximum possible repetitions for each character: freq[i] / k.
🔹 Try building the answer string from length n/k down to 0, as that’s the longest possible length the repeated subsequence can have.
🔹 For each candidate length, recursively try adding characters (following lexicographical order from highest to lowest) while respecting the available frequency quota.
🔹 When a string of required length is built, use isKRepeated to check its validity.
🔹 Backtracking ensures that once we find the first valid sequence for a length, we stop and return it, ensuring it’s the best possible result for that length.









*/



// Approach 1 Backtraking 
// Time Complexity (worst case): O(n * m^{n/k})

// Space Complexity: O(n)
class Solution {
public:

bool isKRepeated(string &s , string &curr, int k ){
    int n = s.length();
    int m = curr.length();

    int idx = 0 ; 
    int count = 0 ; 
    int matchCount = 0 ;

    for(auto &ch : s){
        if(ch == curr[idx]) idx++;

        if(idx == m ){
            idx = 0 ; 
             matchCount++ ;
             if(matchCount == k ) return true;
        }
    }
    return false; 
}

bool backtrack(string &s, int k , vector<char>freqK, vector<int> &requiredFreq, int maxLen ,string &curr, string &result ){
    if(curr.length() == maxLen ){
        if(isKRepeated(s, curr, k)){
            result = curr; 
            return true; 
        }
        return false; 
    }

   for(int i = 0 ; i < freqK.size(); i++){
    if (requiredFreq[i] == 0) continue;
    char ch = freqK[i];
    curr.push_back(ch);
    requiredFreq[i]--;
     if(backtrack(s, k , freqK, requiredFreq, maxLen, curr, result)) return true; 

     curr.pop_back();
     requiredFreq[i]++;
   }
   return false; 
}

    string longestSubsequenceRepeatedK(string s, int k) {
       int n = s.length();

        vector<int>freq(26, 0);

        for(auto &ch : s){
            freq[ch -'a']++;
        }

        vector<char>freqK;
        vector<int>requiredFreq; 
        for(int i  = 25; i>=0; i--){
            if(freq[i] >= k) {
                freqK.push_back(i + 'a');
                requiredFreq.push_back(freq[i] / k) ; 
            }
        }

        int maxLen = n/k;
        string result = "";
        string curr = "";

        for(int len = maxLen ; len>=0; len--){
                if(backtrack(s, k , freqK, requiredFreq, len, curr, result)) return result; 
        }
        return result; 
    }
};








//Approach 2 Greedy , BFS
class Solution {
public:
bool isKRepeated(string &s , string &next , int k ){
    int n = s.length();
    int m = next.length();
    int idx = 0; 
    int matchCount = 0 ; 

    for(auto &ch : s){
        if(ch == next[idx]) idx++;

        if(idx == m ){
            idx = 0 ;  
            matchCount++;

            if(matchCount == k ) return true; 
        }
    }
    return false; 


}
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        string result = "";


        vector<int> freq(26, 0);

        for(int i = 0 ;i <n; i++) freq[s[i] -'a']++; 
        vector<char>freqK; 
        for(int i = 25; i >=0; i--){
            if(freq[i] >= k ) freqK.push_back('a'+i);
        }

        queue<string>q; 
          for(auto &ch : freqK) cout<<ch << " ";
        cout<<endl; 

        for(int i = 0; i < freqK.size(); i++ ){
              q.push(string(1, freqK[i]));
        }


       while(!q.empty()){
          auto curr = q.front(); 
          q.pop();

        
            if(curr.length() > result.length()){
                result = curr; 
            }
          

          for(auto &ch : freqK){
           string next = curr + ch ; 
           if(isKRepeated(s, next , k )){
              q.push(next);
           }
            
          }
       }

       return result; 
    }
};