// 1526. Minimum Number of Increments on Subarrays to Form a Target Array


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int result = target[0]; 
        
        for(int i = 1 ; i  < n ;i++){
            result += max(target[i] - target[i - 1] ,  0);
        }
        return result; 
    }
};