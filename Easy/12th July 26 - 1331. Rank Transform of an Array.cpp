// 1331. Rank Transform of an Array


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int , int>mp ; 
        set<int> st(begin(arr), end(arr));
        int rank = 1; 
        for(auto &x : st){
            mp[x] = rank; 
            rank++;
        }

        vector<int> result(n);
        for(int i = 0 ; i  < n; i++){
            result[i] = mp[arr[i]];
        }
        return result;
    }
};