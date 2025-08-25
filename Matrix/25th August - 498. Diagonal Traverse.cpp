// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

       map<int , vector<int>>mp ; 

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        
        vector<int>result; 
        for(auto [key, vec]: mp){
            if(key%2==1){
                for(int i = 0 ; i < vec.size(); i++){
                    result.push_back(vec[i]);
                }
            }
            else{
                for(int i = vec.size() - 1; i >= 0 ; i--){
                    result.push_back(vec[i]);
                }
            }
        }
    return result; 

    }
};