// 2169. Count Operations to Obtain Zero



// Approach 1 

class Solution {
public:
    int countOperations(int num1, int num2) {
        
        int result = 0 ; 

        while(num1 > 0 && num2 > 0 ){
            if(num1 >= num2){
                num1 -= num2; 
            }
            else num2 -= num1; 
            result++;
        }
        return result; 
    }
};class Solution {
public:
    int countOperations(int num1, int num2) {
        
        int result = 0 ; 

        while(num1 > 0 && num2 > 0 ){
            if(num1 >= num2){
                num1 -= num2; 
            }
            else num2 -= num1; 
            result++;
        }
        return result; 
    }
};



//Approach 2 
class Solution {
public:
int result ; 
void solve(int &num1 , int &num2 ){
    if(num1 == 0 || num2 == 0 ) return; 
      result++;
    if(num1 >= num2){
        num1 -= num2;
      solve(num1, num2);
    } 
    else{
        num2 -=  num1; 
     solve(num1 , num2);
    } 
}
    int countOperations(int num1, int num2) {
        result = 0 ; 
       solve(num1, num2);
       return result; 
    }
};



//Approach 3 
class Solution {
public:
    int countOperations(int num1, int num2) {
        int result = 0 ; 
        while(num1 > 0 && num2 > 0){
              result += num1/num2; 
              num1%=num2; 

              swap(num1, num2);
        }
        return result; 
    }
};