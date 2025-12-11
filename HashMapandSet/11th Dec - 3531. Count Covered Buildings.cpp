// 3531. Count Covered Buildings

// Approach 1 

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
         unordered_map<int , set<int>>rows ; 
         unordered_map<int , set<int>>cols; 
          int result = 0 ; 
         for(auto &b : buildings){
            int x = b[0];
            int y = b[1];

            rows[x].insert(y);
            cols[y].insert(x);
         }
          
         for(auto &b : buildings){
            int x = b[0];
            int y = b[1];

            auto &row  = rows[x];
            auto &col  = cols[y];

            if(row.size() < 3 ) continue; 

            if(y == *row.begin() || y == *prev(row.end())) continue;

            if(col.size() < 3) continue; 

            if(x == *col.begin() || x == *prev(col.end())) continue; 

            result++;


         }
         return result; 
    }
};




//approach 2 
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>minRows(n + 1, n + 1);
        vector<int>minCols(n + 1, n + 1);
        vector<int>maxRows(n + 1, 0);
        vector<int>maxCols(n + 1, 0);

        for(auto &b  : buildings){
            int x = b[0];
            int y = b[1];

            minRows[y] = min(minRows[y], x);
            maxRows[y] = max(maxRows[y], x);
            minCols[x] = min(minCols[x], y);
            maxCols[x] = max(maxCols[x], y);

        }
         
         int result = 0 ; 
        for(auto &b : buildings){
            int x = b[0];
            int y = b[1]; 

            if(x > minRows[y] && x < maxRows[y] && y > minCols[x] && y < maxCols[x]) result++;
        }
        return result; 
    }
};