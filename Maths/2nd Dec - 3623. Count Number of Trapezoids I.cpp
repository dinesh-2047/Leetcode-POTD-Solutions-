// 3623. Count Number of Trapezoids I

class Solution {
public:
int mod = 1e9 + 7; 
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int , int>mp ; 
        
        for(auto &point : points){
            mp[point[1]]++;
        }

    
         long long result = 0 ; 
         long long prev_h_lines = 0 ; 
         for(auto &[_, count] : mp ){
             long long curr_h_lines = (1LL * count * (count - 1))/2;
             result = (result +  (prev_h_lines * curr_h_lines)%mod)%mod; 
             prev_h_lines += curr_h_lines; 
         }
         return result; 
    }
};