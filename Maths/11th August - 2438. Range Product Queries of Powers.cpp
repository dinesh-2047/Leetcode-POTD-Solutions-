// 2438. Range Product Queries of Powers



// Approach 1 

class Solution {
public:
const int mod = 1e9 + 7; 
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<int>powers;
         for(int i = 0 ; i <= 30 ;i++){
            powers.push_back(1<<i);
         }

         int idx = upper_bound(begin(powers), end(powers), n)-begin(powers)-1;
   
         vector<int>p; 
         int sum =0 ; 
         while(idx>= 0 ){
            if(sum == n){
            
                break; 
            }
            if(sum + powers[idx] > n){
                idx--; 
                continue; 
            }
      
            sum += powers[idx];
            p.push_back(powers[idx]%mod);
            idx--; 
         }
   

         reverse(begin(p), end(p));

          vector<int>result(q);
       for(int i = 0 ; i <q; i++){
           int left = queries[i][0];
           int right = queries[i][1];
            
             long long pro = 1 ; 
           for(int j = left ; j<=right; j++){
               pro= (pro * p[j])%mod;
           }
           result[i] = pro; 
       }

       return result; 
    }
};




//Approach 2 
class Solution {
public:
const int mod = 1e9 + 7; 
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<int>powers;
        bitset<32> binary(n);
       int p = 0 ; 
        for(int i = 0; i<binary.size(); i++){
            cout<<binary[i]<<endl; 
            if(binary[i] == 1){
                powers.push_back(1<<p);
            }
            p++;
        }
         
        vector<int>result(q);
       for(int i = 0 ; i <q; i++){
           int left = queries[i][0];
           int right = queries[i][1];
            
             long long pro = 1 ; 
           for(int j = left ; j<=right; j++){
               pro= (pro * powers[j])%mod;
           }
           result[i] = pro; 
       }

       return result; 
    }
};







//Approach 3 
class Solution {
public:
const int mod = 1e9 + 7; 
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<int>powers;
        for(int i = 0 ; i <= 30; i++){
            if((n&(1<<i))!=0){
                powers.push_back(1<<i);
            }
        }

          vector<int>result(q);
       for(int i = 0 ; i <q; i++){
           int left = queries[i][0];
           int right = queries[i][1];
            
             long long pro = 1 ; 
           for(int j = left ; j<=right; j++){
               pro= (pro * powers[j])%mod;
           }
           result[i] = pro; 
       }

       return result; 
    }
};