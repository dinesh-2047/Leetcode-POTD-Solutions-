// 36. Valid Sudoku


// Approach 1 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         
         //check row 
         for(int i = 0 ;i < 9 ;i++){
            unordered_map<int , int>mp ; 
            for(int j = 0 ; j  < 9; j++){
                 if(board[i][j] == '.') continue; 
                 mp[board[i][j]]++;
                 if(mp[board[i][j]] > 1) return false; 
             
            }
         }

         //check col 
         for(int j  = 0 ; j < 9; j++){
            unordered_map<int , int>mp ; 
            for(int i = 0 ; i < 9; i++){
                 if(board[i][j] == '.') continue; 
                   mp[board[i][j]]++;
                   if(mp[board[i][j]] > 1) return false; 
            }
         }

         //check 3 * 3 grid;
         vector<pair<int , int>>starts;

         for(int i = 0 ; i < 9; i+=3){
             for(int j = 0 ; j < 9 ;j+=3){
                  starts.push_back({i, j});
             }
         }

         for(auto &st : starts){
            int row = st.first;
            int col = st.second;
            unordered_map<int ,int >mp ; 
            for(int i = row ; i < row + 3; i++){
                for(int j = col ; j < col + 3; j++){
                    if(board[i][j] == '.') continue; 
                       mp[board[i][j]]++;
                       if(mp[board[i][j]] > 1) return false; 
                }
            }
         }

     return true; 
    }
};










//Approach 2 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check row
        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                mp[board[i][j]]++;
                if (mp[board[i][j]] > 1)
                    return false;
            }
        }

        // check col
        for (int j = 0; j < 9; j++) {
            unordered_map<int, int> mp;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                mp[board[i][j]]++;
                if (mp[board[i][j]] > 1)
                    return false;
            }
        }

        // check 3 * 3 grid;

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_map<int, int> mp;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] == '.')
                            continue;
                        mp[board[i][j]]++;
                        if (mp[board[i][j]] > 1)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};








//Approach 3 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string>st; 
        for(int i = 0 ; i < 9; i++){
            for(int j = 0 ; j  < 9; j++){
                if(board[i][j] == '.') continue; 
                string row = string(1, board[i][j]) + "_row_" + string(1, i);
                string col = string(1, board[i][j]) + "_col_" + string(1, j);
                string box = string(1, board[i][j]) + "3x3" + string(1, i/3) + '-' + string(1, j/3);

                if(st.count(row) || st.count(col) || st.count(box)) return false; 
                st.insert(row);
                st.insert(col);
                st.insert(box);

            }
        }
        return true; 
    }
};