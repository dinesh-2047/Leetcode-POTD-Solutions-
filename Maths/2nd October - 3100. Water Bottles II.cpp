// 3100. Water Bottles II


// Approach 1 
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = 0 ; 
        int empty = 0 ; 

        while(numBottles){

            if(empty == numExchange){
                numBottles += 1; 
                numExchange += 1; 
                empty = 0 ; 
            }
         
          else{
            numBottles -= 1; 

            result += 1;

            empty += 1; 
          }
        }
        if(empty == numExchange){
            result++;
        } 
        return result; 
    }
};





// Approach 2

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles ; 
        while(numBottles >= numExchange){
            result++; 
            numBottles -= numExchange; 
            numExchange++;
            numBottles++;
        }
        return result;
    }
};




// Approach 3\
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + ((-2 * numExchange + 3 + sqrt(4 * pow(numExchange, 2) + 8 * numBottles -12 * numExchange + 1))/2);
    }
};