// K Sized Subarray Maximum


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        
        deque<int>dq; 
        
        vector<int>result; 
        
        for(int i = 0 ; i  < n; i++){
            while(!dq.empty() && dq.front() <=   i- k ) dq.pop_front();
            while(!dq.empty() && arr[i] > arr[dq.back()]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k- 1){
                result.push_back(arr[dq.front()]);
            }
            
        }
        return result; 
        
    }
};