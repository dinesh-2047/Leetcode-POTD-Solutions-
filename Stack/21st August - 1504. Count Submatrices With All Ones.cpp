// 1504. Count Submatrices With All Ones



/*

✨ LeetCode POTD: Count Submatrices With All Ones (1504) 🔢

⁉️ Problem Statement:
🔹 Given a binary matrix mat, return the number of submatrices with all ones.

🔎 My Approaches:

1️⃣ Brute Force with Row Boundaries
🔹 Fix starting row sr and ending row er.
🔹 For each column, check if all values between sr and er are 1.
🔹 Build a temporary array of valid columns (all ones = 1, otherwise 0).
🔹 Count consecutive ones in this array → add to result.

2️⃣ Optimized Row Compression
🔹 Instead of checking each column repeatedly, maintain a temp array initialized with all 1s.
🔹 For each row er, update temp[col] = temp[col] & mat[er][col].
🔹 This ensures temp[col] only stays 1 if the entire column segment (sr → er) has ones.
🔹 Again, count consecutive ones in temp and add to result.

3️⃣ Histogram + Monotonic Stack (Efficient Approach)
🔹 Treat each row as the base of a histogram (heights[col] = consecutive ones up to that row).
🔹 Use a monotonic stack to calculate submatrices efficiently for each row.
🔹 sum[j] stores number of submatrices ending at column j.
🔹 Accumulate sum[j] into result → gives total count.



*/


// Approach 1 
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       int result = 0  ;
        for(int sr = 0 ; sr < m ; sr++){
            for(int er = sr ; er < m ; er++){

                vector<int>temp(n) ; 

               for(int col = 0 ; col < n ; col++){
                   bool allOne = true; 
                for(int row = sr ; row <= er ; row++ ){
                      if(mat[row][col] == 0) allOne = false;
                }
                 if(allOne){
                     temp[col] = 1; 
                 }
                 else temp[col] = 0; 
               }
                  int cnt = 0;
               for(int i = 0 ;i < temp.size(); i++){
                     if(temp[i] == 1){
                        cnt++;
                     }
                     else {
                        cnt = 0 ;
                     }
                     result += cnt; 
               }
            }
        }
        return result; 

    }
};








//Approach 2 
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       int result = 0  ;
        for(int sr = 0 ; sr < m ; sr++){
            vector<int>temp(n, 1);
            for(int er = sr ; er < m ; er++){
              
              for(int col = 0 ; col < n; col++){
                  temp[col] = mat[er][col] & temp[col];
              }


                  int cnt = 0;
               for(int i = 0 ;i < temp.size(); i++){
                     if(temp[i] == 1){
                        cnt++;
                     }
                     else {
                        cnt = 0 ;
                     }
                     result += cnt; 
               }
            }
        }
        return result; 

    }
};













//Approach 3 
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>heights(n, 0);
        int result = 0 ; 

        for(int i =0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                heights[j] = (mat[i][j]==0) ? 0 : heights[j]+1;
            }

            vector<int>sum(n);
            stack<int>st; 

            for(int j = 0 ; j < n ; j++){
                int h = heights[j];
                while(!st.empty() && heights[st.top()] >= h){
                    st.pop();
                }

                if(!st.empty()){
                    sum[j] = sum[st.top()] + heights[j] * (j - st.top() );
                }
                else{
                    sum[j] = heights[j] * (j + 1);
                }
                st.push(j);
                result += sum[j];
            }
        }
        return result; 
    }
};