// 85. Maximal Rectangle

class Solution {
public:
int m ,n ; 
vector<int> findNSE(vector<int> &heights){
    stack<int>st; 
    vector<int>nge(n, n);

    for(int i = n-1; i>= 0 ;i--){
        while(!st.empty() && heights[st.top()] >= heights[i] ){
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        st.push(i);
    }
    return nge; 
}

vector<int> findPSE(vector<int> &heights){
    stack<int>st; 
    vector<int>pse(n, -1);

    for(int i = 0 ; i  < n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(!st.empty()) pse[i] = st.top();
        st.push(i);
    }
    return pse; 
}


int maxArea(vector<int> &heights){

    vector<int>pse = findPSE(heights);
    vector<int>nse = findNSE(heights);

    vector<int> width(n);

    for(int i = 0 ; i  < n; i++){
        width[i] = nse[i] - pse[i] - 1; 
    }
      
    int maxi = 0 ; 
    for(int i = 0 ; i  < n; i++){
        maxi = max(maxi , heights[i] * width[i]);
    }
    return maxi ; 
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<int>heights(n , 0);

        int result = 0;

        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ;j  < n; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0; 
                }
                else heights[j]++;
            }
            result = max(result , maxArea(heights));
        }
        return result; 
    }
};