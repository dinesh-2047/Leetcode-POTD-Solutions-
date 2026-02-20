// 761. Special Binary String

class Solution {
public:
int n ;
string solve(string &s){
    int sum  = 0 ; 
    int start = 0 ; 
    vector<string>specials;
    for(int i = 0 ; i   < s.length(); i++){
        if(s[i] == '1'){
            sum += 1; 
        }
        else sum -= 1; 

        if(sum == 0 ){
            string inner = s.substr(start+1, i - start - 1);
            specials.push_back("1" + solve(inner) + "0");
            start = i + 1; 
        
    }
    }
    sort(rbegin(specials), rend(specials));
    string result = "";
    for(auto &s : specials) result += s; 
    return result;
}

    string makeLargestSpecial(string s) {
         n = s.length();
       
       return solve(s);
    }
};