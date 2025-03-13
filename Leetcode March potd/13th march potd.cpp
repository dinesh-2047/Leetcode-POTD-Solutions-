// 3356. Zero Array Transformation II


class Solution {
    public:
    // TC = log(q)*(q + n );
    bool checkWithDifferenceArray(int k , vector<int>& num , vector<vector<int>> &queries){
        int n = num.size();
        vector<int>diff(n,0);
    
        for(int i = 0 ; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
    
            diff[l] +=  val;
            if(r+1 < n)
            diff[r+1] -=val;
        }
             
             int cumSum = 0 ; 
            for(int i = 0 ; i<n; i++){
                 cumSum += diff[i];
                 diff[i] = cumSum;
    
                 if(num[i]-diff[i]>0  ) return false; 
            
    
         }
         return true;
    }
    
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int q = queries.size();
            int ans = 0 ;
    
            auto lambda = [](int num){
                return num == 0;
            };
    
            if(all_of(begin(nums) , end(nums) , lambda)){
                return 0 ; 
            }
            int l = 0 ;
            int r = q-1;
    
            while (l<=r){
                int mid = l + (r-l)/2;
                 if(checkWithDifferenceArray(mid , nums, queries)==true){
                         ans = mid+1;
                         r = mid - 1;
                 }
                 else l = mid + 1;
            
            }
          
               
            return (ans == 0 ) ? -1 : ans;
        }
    };