// 1716. Calculate Money in Leetcode Bank


// Approach 1  simulation 
class Solution {
public:
    int totalMoney(int n) {
        int prevMonday = 1 ; 
        int result = 0 ; 
        int curr = 0 ; 

        for(int day = 1; day <= n ; day++){
               curr++;
                result += curr; 
            if(day % 7 == 0 ){
                 curr = prevMonday ; 
                prevMonday++;
              
            }
        
          
        }
        return result; 
    }
};





//Approach 2 loop  + Arithmatic Progression 
class Solution {
public:
    int totalMoney(int n) {
       if(n <= 7 ) return (n*(n + 1))/2;

       int weeks = n/7; 
       int extra_days = n%7; 

       int result = 0 ; 

       int firstTerm = 28; 
       int lastTerm = firstTerm + (weeks - 1) * 7; 
       result  += weeks * (firstTerm + lastTerm)/2;

       int money = weeks + 1; 
       for(int day =1 ; day <= extra_days ; day++){
            result += money; 
            money++;
       }
       return result; 

    }
};





//Approach 3 without loop  + Arithmatic Progression 
class Solution {
public:
    int totalMoney(int n) {
       if(n <= 7 ) return (n*(n + 1))/2;

       int weeks = n/7; 
       int extra_days = n%7; 

       int result = 0 ; 

       int firstTerm = 28; 
       int lastTerm = firstTerm + (weeks - 1) * 7; 
       result  += weeks * (firstTerm + lastTerm)/2;

       int extra_days_first_term = 1 + weeks ; 
       int extra_days_last_term = extra_days_first_term + (extra_days - 1) * 1; 

       result += extra_days * (extra_days_first_term + extra_days_last_term)/2;

       return result; 

    }
};