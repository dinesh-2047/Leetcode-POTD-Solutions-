// Next Greater Element in Circular Array


class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
         int n = arr.size();
        vector<int>result(n , -1);
         
        stack<int>st; 
        for(int i = n-1; i>=0 ;i--){
            st.push(i);
        }
        
        
        
        for(int i = n-1; i >= 0 ;i--){
            while(!st.empty() && arr[st.top()] <= arr[i] ){
                st.pop();
            }
            
            if(!st.empty()){
                result[i] = arr[st.top()];
            }
            else result[i] = -1 ; 
            
            st.push(i);
        }
        return result; 
    }
};