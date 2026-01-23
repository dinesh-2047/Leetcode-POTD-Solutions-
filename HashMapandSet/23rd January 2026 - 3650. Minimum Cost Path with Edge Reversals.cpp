// 3650. Minimum Cost Path with Edge Reversals


class Solution {
public:
using ll = long long; 
    int minimumPairRemoval(vector<int>& temp) {
        int n = temp.size();

        vector<ll>nums(n); 
        for(int i = 0 ; i < n; i++){
            nums[i] = (ll)temp[i];
        }

        int bad = 0 ; 
        for(int i = 0 ; i  < n - 1; i++){
            if(nums[i]  > nums[i  + 1]) bad++;
        }
        if(bad == 0 ) return 0 ; 

        set<pair<ll , int>>st; 
        vector<int>prevIdx(n); 
        vector<int>nextIdx(n);

        for(int i = 0 ; i  < n-1; i++){
            st.insert({nums[i] + nums[i + 1], i});
        }

        for(int i = 0 ;i< n; i++){
            prevIdx[i] = i - 1;
            nextIdx[i] = i +1 ; 
        } 
       
        int result = 0 ;
        while(bad > 0 ){
            int first = st.begin()->second; 
            int second = nextIdx[first];
            int first_left =  prevIdx[first]; 
            int second_right = nextIdx[second];


            st.erase(begin(st));

            if(nums[first] > nums[second]){
                bad--;
            } 
          
             if(first_left >= 0 ){
            if(nums[first_left] > nums[first] && nums[first_left] <= nums[first] + nums[second]){
                bad--;
            }
            else if(nums[first_left] <= nums[first] && nums[first_left] > nums[first] + nums[second]) bad++;
             }

             if(second_right < n ){
                if(nums[second_right] >= nums[second] && nums[second_right] < nums[first] + nums[second]) bad++;
                else if(nums[second_right] < nums[second] && nums[second_right] >= nums[first] + nums[second]) bad--;
             }
             
             if(first_left >= 0 ){
             st.erase({nums[first_left]+ nums[first], first_left});
             st.insert({nums[first_left] + nums[first] + nums[second], first_left});
             }
            if(second_right < n ){
             st.erase({nums[second] + nums[second_right], second});
             st.insert({nums[first] + nums[second] + nums[second_right] , first});
             prevIdx[second_right] = first; 
            }

            
           nextIdx[first] = second_right; 
           nums[first] += nums[second];
           result++;

            
        }

        return result; 
        
    }
};