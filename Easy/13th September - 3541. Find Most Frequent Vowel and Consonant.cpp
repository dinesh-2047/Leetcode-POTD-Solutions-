// 3541. Find Most Frequent Vowel and Consonant



// Approach 1 
class Solution {
public:
bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
}

    int maxFreqSum(string s) {
        int n = s.length();

         unordered_map<char , int>mp ; 
         for(auto &ch : s) mp[ch]++;
          
         int maxi_c = 0 ; 
         int maxi_v = 0; 
         
          for(auto &[ch, freq] : mp){
              if(isVowel(ch)){
                maxi_v = max(maxi_v, freq);
              }
              else maxi_c = max(maxi_c, freq);
          }

        return maxi_c + maxi_v;
    }
};





//approach 2 
class Solution {
public:
bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
}

    int maxFreqSum(string s) {
        int n = s.length();

         unordered_map<char , int>mp ; 
         for(auto &ch : s) mp[ch]++;
          
         int maxi_c = 0 ; 
         int maxi_v = 0; 
         
          for(auto &[ch, freq] : mp){
              if(isVowel(ch)){
                maxi_v = max(maxi_v, freq);
              }
              else maxi_c = max(maxi_c, freq);
          }

        return maxi_c + maxi_v;
    }
};