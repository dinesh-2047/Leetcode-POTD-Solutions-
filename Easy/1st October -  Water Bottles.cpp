// 1518. Water Bottles


// Approach 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int result = 0 ; 
       int empty = 0 ; 

       while(numBottles){
          result += numBottles; 
          empty += numBottles; 

          numBottles = empty / numExchange; 
          empty = empty % numExchange; 
       }
       return result; 
    }
};




//Approach 2 
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0; 
        
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            empty += numExchange; 
            numBottles += 1; 

        }
        return empty  + numBottles; 
    }
};







//Approach 3 
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1)/(numExchange - 1);
    }
};