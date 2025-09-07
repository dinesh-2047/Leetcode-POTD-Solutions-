// 1304. Find N Unique Integers Sum up to Zero


// Approach 1
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result(n); 
        if(n%2 == 0){
            int temp = -n;
            for(int i = 0 ; i < n/2 ; i++){
                result[i] = temp++ ; 
                
            }
            temp = n; 
            for(int i = n/2; i < n; i++){
              result[i] = temp--;
            }
        }
        else{
             int temp = -n;
            for(int i = 0 ; i < n/2 ; i++){
                result[i] = temp++ ; 
                
            }
            temp = n; 
            for(int i = n/2 + 1; i < n; i++){
              result[i] = temp--;
            }
            result[n/2] = 0 ; 
        }
        return result; 
    }
};






//Approach 2 
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result(n,0); 
        for(int i = 0 ; i < n; i+=2){
           if(i + 1< n ){
            result[i] = (i+1);
            result[i+1] = -(i+1);
           }
          
        }
        return result; 
    }
};









//Approach 3 
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result(n,0); 
        int i = 0 ; 
        int j = n-1;

        while(i < j ){
            result[i] = i+1;
            result[j] = -(i + 1);
            i++;
            j--;
        }
        return result;
    }
};