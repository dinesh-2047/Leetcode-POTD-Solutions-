// 3066. Minimum Operations to Exceed Threshold Value II 

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size();
           
    
            priority_queue<long long  , vector<long long>, greater<long long >>pq(nums.begin(),nums.end());
            int op = 0;
    
            while(!pq.empty()){
    
               if(pq.top()>=k) return op ; 
    
               auto x = pq.top();
               pq.pop();
               auto y = pq.top();
               pq.pop();
    
    
            pq.push(1LL * min(x, y) * 2 + 1LL * max(x, y));
    
               op++;
    
    
            }
            return -1;
    
    
        }
    };