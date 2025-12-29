// 756. Pyramid Transition Matrix


class Solution {
public:
unordered_map<string , bool>dp; 
bool solve(string curr, string above, int i , unordered_map<string , vector<char>> &mp){
    if(curr.length() == 1) return true; 

    string key = curr + '_' + to_string(i) + '_' + above; 

    if(dp.count(key)) return dp[key];

    if(i == curr.length() - 1){
      return dp[key] = solve(above, "", 0, mp);
            
    }

    string pair = curr.substr(i, 2);
    if(!mp.count(pair)){
        return dp[key] =  false; 
    }

    for(auto &ch : mp[pair]){
        above.push_back(ch);
        if(solve(curr, above, i + 1, mp)){
            return dp[key] =  true; 
        }
        above.pop_back();
    }
    return dp[key] = false; 
}

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string , vector<char>>mp ; 

        for(auto &allow : allowed){
            string s = allow.substr(0, 2);
            mp[s].push_back(allow[2]);
        }

        string curr = bottom ; 
        string above = "";

        return solve(curr, above , 0, mp);
    }
};