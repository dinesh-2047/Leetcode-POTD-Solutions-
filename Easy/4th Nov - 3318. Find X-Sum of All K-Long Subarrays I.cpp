// 3318. Find X-Sum of All K-Long Subarrays I





// Approach 1  using map + maxheap 
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int>result(n-k + 1, 0);

        for(int i = 0 ; i < n - k + 1; i++){
            unordered_map<int , int>mp ; 
            for(int j = i ; j  <i+k; j++){
                mp[nums[j]]++;
            }
              priority_queue<pair<int , int>>pq; 
            for(auto &[num , freq] : mp){
                   pq.push({freq, num});
            }

            int count = 0 ; 
            while(!pq.empty() && count < x){
                result[i] += (pq.top().second * pq.top().first);
                pq.pop();
                
                count++;
            }

        }
        return result; 
    }
};






//using map + min heap 
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int>result(n-k + 1, 0);
        unordered_map<int , int>mp ; 

       int i = 0 ; 
       int j = 0 ; 

       while(j < n ){
            mp[nums[j]]++;

            if(j - i + 1 == k ){
                priority_queue<pair<int , int>, vector<pair<int , int>>, greater<>>pq; 
                for(auto &[num, freq] : mp){
                    pq.push({freq, num});
                    if(pq.size() > x){
                        pq.pop();
                    }
                }

                while(!pq.empty()){
                    result[i] += (pq.top().first * pq.top().second); 
                    pq.pop();
                }

                mp[nums[i]]--;
                if(mp[nums[i]] == 0 ){
                    mp.erase(nums[i]);
                }
                i++;
            
            }
            j++;
        }
        return result; 
    }
};