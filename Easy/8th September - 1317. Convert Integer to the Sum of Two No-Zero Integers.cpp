// 1317. Convert Integer to the Sum of Two No-Zero Integers


// Approach 1:

class Solution {
public:
bool non_zero(int n ){
    while(n){
        if(n%10 == 0 ) return false;
        n/=10;

    }
    return true; 
}

    vector<int> getNoZeroIntegers(int n) {
        for(int  a = 1; a < n; a++){
            int b = n-a;
            if(non_zero(a) && non_zero(b)){
                return {a, b};
            }
        }
        return {};
    }
};







//Approach 2
class Solution {
public:
bool non_zero(int n ){
    while(n){
        if(n%10 == 0 ) return false;
        n/=10;

    }
    return true; 
}

    vector<int> getNoZeroIntegers(int n) {

       int st = 1; 
       int end = n-1; 

       while(st <= end){
        int a = st + (end - st)/2; 
            int b = n-a;
            if(non_zero(a) && non_zero(b)){
                return {a, b};
            }else {
                st = a + 1; 
            }
        }
        return {};
    }
};







//Approach 3 
class Solution {
public:

    vector<int> getNoZeroIntegers(int n) {
        int placeValue = 1; 
        int a = n; 
        int b = 0 ; 
        while(n > 1){
            int take = 1; 
            if(n%10 == 1){
                take = 2; 
            }
            a = a - (take * placeValue);
            b = b + (take * placeValue);

            n = (n- take)/10; 
            placeValue *= 10; 

        }
        return {a, b};
       
    }
};