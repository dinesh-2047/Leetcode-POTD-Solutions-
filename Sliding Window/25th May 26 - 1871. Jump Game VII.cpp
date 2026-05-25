// 1871. Jump Game VII

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length() ;
        if(s[n-1] != '0') return false;
        vector<bool> visited(n , false);
        visited[0] = true; 
        
        int prev = 0; 
        for(int i = 0 ; i  < n; i++){
            if(!visited[i]) continue; 
            int st = max(prev + 1, i + minJump);
            int end = min(i + maxJump, n-1);

            for(int j = st; j  <= end; j++){
                if(j == n - 1) return true; 
                if(s[j] == '0') visited[j] = true; 
                prev = max(prev, j);
            }
        }
        return false; 
    }
};