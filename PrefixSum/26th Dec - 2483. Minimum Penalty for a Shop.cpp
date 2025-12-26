
// =2483. Minimum Penalty for a Shop



// Approach 1

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int>prefN(n+1); 
        vector<int>suffY(n+1); 

        int countN = 0 ; 
        for(int i = 0 ; i < n; i++){
            prefN[i] = countN; 
            if(customers[i] == 'N') countN++;
        }
        prefN[n] = countN; 

        int countY =  0; 
        for(int i = n-1; i >= 0 ; i--){
            if(customers[i] == 'Y') countY++;
            suffY[i] = countY; 
        }

        int result = 0;
        int minPenality = INT_MAX;

        for(int i = 0 ; i <= n; i++){
             int penality = prefN[i] + suffY[i];
             if(minPenality > penality){
                 result = i ; 
                 minPenality = penality ; 
             }
        }  

       return result; 

    }
};



//Approach 2
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int result = 0 ; 
        int penality = count(begin(customers), end(customers), 'Y');
        int minPenality = penality ; 

        for(int i = 0 ; i < n; i++){
            if(customers[i] == 'Y'){
                penality--; 
            }
            else penality++;

            if(minPenality > penality){
                minPenality = penality ; 
                result = i + 1; 
            }
        }
        return result; 
    }
};