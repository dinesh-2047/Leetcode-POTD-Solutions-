// 1200. Minimum Absolute Difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>result; 

        sort(begin(arr), end(arr));

        int minDiff = INT_MAX ; 
        for(int i = 0; i < n-1; i++){
            if(minDiff > abs(arr[i] - arr[i + 1])){
                minDiff = abs(arr[i] - arr[i + 1]);
            }
        }

        for(int i = 0 ; i  < n-1; i++){
            int diff = abs(arr[i] - arr[i + 1]);
            if(diff  == minDiff){
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result; 
    }
};