// 1415. The k-th Lexicographical String of All Happy Strings of Length n


class Solution {
public:
int count = 0 ; 
string result = "";
void solve(int n , string curr, int k){
    if(curr.length() == n ){
         count++;
         if(count == k ) {
            result = curr; 
         }
         return ;
    }

    for(char ch = 'a'; ch <= 'c'; ch++){
        if(!curr.empty() && curr.back() == ch) continue; 
   
        curr.push_back(ch);
        
        solve(n , curr, k);
        curr.pop_back();
    }
}

    string getHappyString(int n, int k) {
        string curr = "";

        solve(n , curr, k);
        
        return result;

    }
};