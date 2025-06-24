// 2200. Find All K-Distant Indices in an Array

//Approach 1
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st ;
        int n = nums.size();
        
        for(int i = 0 ; i<n; i++){
            for(int j = max(0, i-k) ; j <n ; j++){
                if(abs(i-j) <= k && nums[j] == key) st.insert(i);
            }
        }
         return vector<int>(st.begin(), st.end()); 
    }
};



//Approach 2 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>result ;
        int n = nums.size();
        
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j <n ; j++){
                if(abs(i-j) <= k && nums[j] == key) {
                    result.push_back(i);
                    break; 
            }
        }
        }
         return result; 
    }
};







//Approach 3 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int>result; 

        for(int i = 0 ; i <n; i++){
            if(nums[i] == key){
                int start = max(0,i-k);
                int end = min(n-1, i+k);

                if(!result.empty() && result.back() >= start){
                    start = result.back()+1;
                }

                for(int j = start; j<=end; j++) result.push_back(j);
            }
        }
        return result; 
    }
};