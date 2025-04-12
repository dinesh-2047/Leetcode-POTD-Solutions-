// 3272. Find the Count of Good Integers


class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string>st; 
            int d = (n+1)/2;
            int start = pow(10,d-1);
            int e = pow(10 , d ) -1;
            long long ans = 0 ; 
    
    
            for(int num = start; num <= e; num++ ){
                string lefthalf = to_string(num);
                
                string full = "";
    
                if(n%2==0){
                    string righthalf = lefthalf;
                    reverse(righthalf.begin(), righthalf.end());
    
                    full = lefthalf + righthalf; 
                }
                else {
                    string righthalf = lefthalf.substr(0,d-1);
                    reverse(righthalf.begin(), righthalf.end());
                    full = lefthalf + righthalf; 
                }
    
                long long number = stoll(full) ;
    
                if(number%k!=0) continue; 
                sort(begin(full) , end(full));
                 st.insert(full);
            }
    
    
         //precompute factorial 
         vector<long long>factorial(11,1);
         for(int i = 1; i<11; i++){
            factorial[i] = factorial[i-1] * i ;
         }
    
    
            for(auto &s : st){
                vector<int>count(10, 0);
                for(auto &ch : s){
                    count[ch-'0']++;
                }
    
                int totalDigits = s.length();
    
                int zeroDigits = count[0];
                int nonZeroDigits = totalDigits - zeroDigits; 
    
                long long permutations = (nonZeroDigits * factorial[totalDigits - 1]);
    
                for(int i = 0 ; i<10; i++){
                    permutations /= factorial[count[i]];
                }
    
                ans += permutations; 
            }
    
            return ans; 
        }
    };