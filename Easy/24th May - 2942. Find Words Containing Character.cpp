// 2942. Find Words Containing Character

//Approrach 1 
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;

        for(int i = 0 ; i < words.size(); i++){
            string s = words[i];

            for(auto &ch : s){
                if(ch == x){
             ans.push_back(i);
                break; 
                }
            }
        }
        return ans; 
    }
};





//Approach 2 
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;

        for(int i = 0 ; i < words.size(); i++){
            string s = words[i];

           if(s.find(x)!=string::npos) ans.push_back(i);
        }
        return ans; 
    }
};









//Approach 3 
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        
        auto lambda = [&x](char ch ){
            return ch==x;
        };
        for(int i = 0 ; i < words.size(); i++){
            string s = words[i];

           if(any_of(s.begin(), s.end(), lambda)) ans.push_back(i);
        }
        return ans; 
    }
};