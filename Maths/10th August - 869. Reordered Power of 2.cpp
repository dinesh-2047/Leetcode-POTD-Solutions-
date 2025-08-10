// 869. Reordered Power of 2


// Approach 1 
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n <= 0 ) return 0; 
        vector<int>nums ; 
        while(n){
            nums.push_back(n%10);
            n/=10; 
        }
        //    cout<<n; 
        reverse(begin(nums), end(nums));
        sort(begin(nums), end(nums));
        
     

        do{ 
          
            if(nums[0] == 0 ) continue; 
            //   cout<< nums.size()<<endl; 
              int x =0 ; 
           for(int i =0 ; i  <nums.size() ; i++ ){
              x  = x * 10 +  nums[i];

           }
           cout<<x<<endl; 
           if(__builtin_popcount(x) == 1) return true; 
        }
        while(next_permutation(begin(nums), end(nums)));

        return false; 
    }
};





//Approach 2 
class Solution {
public:
    bool reorderedPowerOf2(int n) {
         string s = to_string(n);
         sort(begin(s), end(s));

         for(int i = 0 ;i  <= 30; i++){
            int x = pow(2, i);
            string str = to_string(x);
            sort(begin(str), end(str));
            if(str == s) return true; 
         }
          return false; 
    }
};










//Approach 3 

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st; 
        for(int i = 0 ; i  <= 29; i++){
            int x = 1 << i ; 
            string s = to_string(x);
            sort(begin(s), end(s));
          st.insert(s);
        }

        string s = to_string(n);
        sort(begin(s), end(s));
        if(st.count(s)) return true; 
        else return false; 
    }
};







//Approach 4 
class Solution {
public:
    bool reorderedPowerOf2(int n) {
       vector<int>count(10, 0);
       while(n){
          count[n%10]++;
          n/=10; 
       }

       for(int i = 0 ; i <= 29; i++){
           vector<int>cnt(10, 0);
           int x = pow(2, i);  
            while(x){
                cnt[x%10]++;
                x/=10; 
            }
            if(count == cnt) return true; 
       }
       return false; 
    }
};








//Approach 5 
class Solution {
public:
int getFreqNum(int n ){
    
    int num = 0 ; 
    while(n){
        num += pow(10, (n%10));
        n/=10;
    }
    return num ;
}

    bool reorderedPowerOf2(int n) {
        int num = getFreqNum(n);

        for(int i = 0 ; i  <=29; i++){
            int x = getFreqNum(1<<i);
            if(num == x) return true; 
        }
        return false; 
    }
    
};