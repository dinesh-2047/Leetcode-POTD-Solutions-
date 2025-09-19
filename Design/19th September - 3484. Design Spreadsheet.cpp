// 3484. Design Spreadsheet


// Appraoch 1 
class Spreadsheet {
public:
vector<vector<int>>spreadsheet; 
    Spreadsheet(int rows) {
        spreadsheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
         int col = cell[0] -'A';
         int row = stoi(cell.substr(1))-1;

         spreadsheet[row][col] = value; 
    }
    
    void resetCell(string cell) {
          int col = cell[0] -'A';
         int row = stoi(cell.substr(1))-1;

         spreadsheet[row][col] = 0 ; 
    }
    
    int getValue(string formula) {
        int n = formula.length();
      
        string s1 = "";
        string s2 = "";

        int i = 1 ; 
        while(i < n && formula[i] != '+'){
             s1.push_back(formula[i]);
             i++;
        }
        i++;
        while(i < n ){
            s2.push_back(formula[i]);
            i++;
        }

        int x = 0 ; 
        int y  = 0;
        if(isdigit(s1[0])){
            x = stoi(s1);
        } 
        else{
            int col = s1[0] - 'A';
            int row = stoi(s1.substr(1))-1;

            x = spreadsheet[row][col];
        }

        if(isdigit(s2[0])){
            y = stoi(s2);
        }
        else{
            int col = s2[0] - 'A';
            int row = stoi(s2.substr(1))-1;
            y = spreadsheet[row][col];
        }
        return x + y; 

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */






 //Approach 2 
 class Spreadsheet {
public:
unordered_map<string , int>spreadsheet; 
    Spreadsheet(int rows) {
       
    }
    
    void setCell(string cell, int value) {
         spreadsheet[cell] = value; 
    }
    
    void resetCell(string cell) {
         spreadsheet[cell] = 0 ; 
    }
    
    int getValue(string formula) {
        int n = formula.length();
      
        string cell1 = "";
        string cell2 = "";

        int i = 1 ; 
        while(i < n && formula[i] != '+'){
             cell1.push_back(formula[i]);
             i++;
        }
        i++;
        while(i < n ){
            cell2.push_back(formula[i]);
            i++;
        }

        int x = 0 ; 
        int y  = 0;
        if(isdigit(cell1[0])){
            x = stoi(cell1);
        } 
        else{
            x = spreadsheet[cell1];
        }

        if(isdigit(cell2[0])){
            y = stoi(cell2);
        }
        else{
           y = spreadsheet[cell2];
        }
        return x + y; 

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */