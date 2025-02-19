// 1415. The k-th Lexicographical String of All Happy Strings of Length n


// Approach 1 ; 

class Solution {
    public:
    void  backtrack(int n , vector<string> &ans, string &curr) {
        if(curr.length()==n) {
            ans.push_back(curr);
            return ; 
        }
    
        for(char ch = 'a'; ch<='c'; ch++){
    
            if(!curr.empty () && ch==curr.back()) continue; 
    
            curr.push_back(ch);
    
            backtrack(n , ans, curr);
    
    
            curr.pop_back();
    
    
            
        }
    }
        string getHappyString(int n, int k) {
           vector<string>ans;
    
           string curr = "";
    
            backtrack(n , ans, curr );
    
            if(k > ans.size()) return "";
            else return ans[k-1];
        }
    };