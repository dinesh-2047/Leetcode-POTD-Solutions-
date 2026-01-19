// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold


// Approach 1 prefix sum + linear search
class Solution {
public:
vector<vector<int>>prefSum; 
bool isValid(vector<vector<int>> &mat, int &threshold , int len  , int i , int j ){
     int sum = 0;
     int x = i + len - 1 ; 
     int y = j + len - 1 ; 

     sum += prefSum[x][y];
     if(i > 0) sum -= prefSum[i - 1][y];
     if(j > 0) sum -= prefSum[x][j -1];
     if(i > 0 && j > 0 ) sum += prefSum[i - 1][j -1 ];

     return sum <= threshold; 
}

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        prefSum.assign(m, vector<int>(n , 0));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j  < n ;j++){
                prefSum[i][j] = mat[i][j];
                if(i > 0 ) prefSum[i][j] += prefSum[i - 1][j];
                if(j > 0 ) prefSum[i][j] += prefSum[i ][j-1];
                if(i > 0 && j > 0 ) prefSum[i][j] -= prefSum[i - 1][j-1];
            }
        }

        int result = 0 ; 

        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ;j < n; j++){
                for(int len = 1; len <= min(m-i, n-j); len++){
                    if(isValid(mat, threshold, len, i , j)){
                        result = max(result , len);
                    }
                }
            }
        }
        return result; 
    }
};


//Approach 2 prefixSum + binary search 
class Solution {
public:
vector<vector<int>>prefSum; 
bool isValid(vector<vector<int>> &mat, int &threshold , int len  , int i , int j ){
     int sum = 0;
     int x = i + len - 1 ; 
     int y = j + len - 1 ; 

     sum += prefSum[x][y];
     if(i > 0) sum -= prefSum[i - 1][y];
     if(j > 0) sum -= prefSum[x][j -1];
     if(i > 0 && j > 0 ) sum += prefSum[i - 1][j -1 ];

     return sum <= threshold; 
}

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        prefSum.assign(m, vector<int>(n , 0));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j  < n ;j++){
                prefSum[i][j] = mat[i][j];
                if(i > 0 ) prefSum[i][j] += prefSum[i - 1][j];
                if(j > 0 ) prefSum[i][j] += prefSum[i ][j-1];
                if(i > 0 && j > 0 ) prefSum[i][j] -= prefSum[i - 1][j-1];
            }
        }

        int result = 0 ; 

        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ;j < n; j++){
                int l = 1; 
                int r = min(m-i, n-j);

                while( l <= r){
                    int mid = l + (r-l)/2;
                     if(isValid(mat, threshold, mid, i , j)){
                        result = max(result , mid) ; 
                        l = mid + 1; 
                    }
                    else r = mid -1 ; 
                } 
                
            }
        }
        return result; 
    }
};