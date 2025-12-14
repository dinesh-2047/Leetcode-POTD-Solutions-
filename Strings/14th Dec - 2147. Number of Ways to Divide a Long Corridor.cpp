// 2147. Number of Ways to Divide a Long Corridor


class Solution {
public:
int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();

        int count_s = 0 ; 
        for(auto &c : corridor){
            if(c == 'S') count_s++;

        }

        if(count_s%2 == 1 || count_s == 0 ) return 0;

        if(count_s == 2) return 1; 

         int seats = 0 ; 
         long long result = 1; 

         
         int i = 0 ; 
         while( i < n ){
            if(corridor[i] == 'S'){
                seats++;
                count_s--;
            }
              int j = i + 1; 
            if(seats == 2){
               
                int count_p = 0 ; 
                while(j < n && corridor[j] == 'P'){
                    count_p++;
                   j++;
                }
                if(count_s != 0 )
                result = (result * (count_p + 1)) %mod; 
                seats = 0 ; 
            }
            i = j ;
            
         }
         return result;
    }
};