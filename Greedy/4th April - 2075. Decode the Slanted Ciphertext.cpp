// 2075. Decode the Slanted Ciphertext

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        vector<vector<char>>grid(rows , vector<char>(n/rows));
        int idx = 0 ; 
        for(int i = 0 ; i  < rows; i++){
            for(int j = 0 ; j  < n/rows; j++){
                if(idx < n ){
                    grid[i][j] = encodedText[idx++];
                }
            }
        }

        string result = "";
       for(int j = 0 ; j < n/rows; j++){
             int col = j; 
          for(int i = 0 ; i  < rows; i++){
                if(col < (n/rows))
               result.push_back(grid[i][col++]);
          }
       }


        idx = result.length()-1; 
       while(idx >= 0 && result[idx] == ' ' ){
              idx--;
       }

       result = result.substr(0, idx + 1);
        return result; 
    }
};