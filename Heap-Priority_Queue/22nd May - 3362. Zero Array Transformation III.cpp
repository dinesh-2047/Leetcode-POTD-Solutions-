// 3362. Zero Array Transformation III



class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        

       sort(queries.begin(), queries.end());
       priority_queue<int>pq; 
       priority_queue<int ,vector<int>, greater<>>past; 

       int usedCount = 0 ; 
       int j = 0; 
       for(int i = 0 ; i<n; i++ ){
           
           while(j<q && i==queries[j][0]){
            pq.push(queries[j][1]);
            j++;
           }
           
            nums[i] -= past.size();

            while(nums[i] > 0 && !pq.empty() &&  pq.top() >= i){
                int ending = pq.top();
                pq.pop();
                past.push(ending);
                usedCount++;
                nums[i]--;
            }

            if(nums[i] > 0 ) return -1;

             
           while(!past.empty() && past.top() <= i){
            past.pop();
           }
       }

       
        return q - usedCount;

    }
};