// 3043. Find the Length of the Longest Common Prefix



class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int  n = arr1.size();
        int m  = arr2.size();
        unordered_map<int , int>mp; 

        for(int i = 0 ; i  < n; i++){
            string s = to_string(arr1[i]);
            for(int len = 1; len <= s.length() ; len++){
                string str = s.substr(0, len);
                int num = stoi(str);
                mp[num]++;
            }
        }
          int result =0 ; 
        for(int i = 0 ; i  < m; i++){
            string s = to_string(arr2[i]);
            for(int len = 1; len <= s.length() ; len++){
                string str = s.substr(0, len);
                int num = stoi(str);
                if(mp.count(num)){
                    result = max(result, (int)str.length());
                }
            }
        }
        return result;


    }
};  