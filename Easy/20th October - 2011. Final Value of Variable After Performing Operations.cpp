// 2011. Final Value of Variable After Performing Operations


// Approach  1
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0 ; 
        for(auto &s : operations){
            if(s == "X++" || s == "++X"){
                x++;
            }
            else x--;
        }
        return x; 
    }
};






//approach2  
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0 ; 
        for(auto &s : operations){
            if(s[1] == '+'){
                x++;
            }
            else x--;
        }
        return x; 
    }
};