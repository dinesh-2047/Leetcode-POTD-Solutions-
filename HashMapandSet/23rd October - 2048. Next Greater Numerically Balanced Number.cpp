// 2048. Next Greater Numerically Balanced Number


// Approach 1 brute force with limit 
class Solution {
public:
    int nextBeautifulNumber(int n) {
        if(n == 0 ) return 1; 
        unordered_map<int , int>ml = {{1, 1}, {2, 22}, {3, 333}, {4, 4444}, {5, 55555}, {6, 666666}, {7, 7777777}}; 
        unordered_map<int , int>ms = {{1, 1}, {2 ,22}, {3, 122}, {4, 1333}, {5, 14444}, {6, 122333}, {7, 1224444}}; 

        int digits = floor(log10(n)) + 1; 

        int limit = ml[digits];
        if(n >= limit) return ms[digits + 1];

        else{
            for(int num = n + 1; num <= limit; num++ ){
                int temp = num; 
                unordered_map<int , int>mp ; 
                while(temp){
                    mp[temp%10]++;
                    temp/=10; 
                }

                bool isValid = true; 
                for(auto &[digit, freq] : mp){
                    if(digit != freq){
                        isValid = false; 
                        break; 
                    }
                }
                if(isValid) return num; 
            }
        }
        return 0 ; 
    }
};










//Approach 2 simple brute force 
class Solution {
public:
    int nextBeautifulNumber(int n) {
         if(n >= 666666) return 1224444;
         int num = n + 1; 

         while(true){
                int temp = num; 
               vector<int>freq(10, 0);  
                while(temp){
                    freq[temp%10]++;
                    temp/=10; 
                }

                bool isValid = true; 
                for(int i = 0 ; i < 10; i++){
                    if(freq[i] == 0 ) continue; 
                    if(i != freq[i]){
                        isValid = false; 
                        break; 
                    }
                }
                if(isValid) return num; 
                num++;
            }
        
        return 0 ; 

          
    }
};










//Approach 3 precumputed list  + binary search
class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int>beautifulNums = {1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555, 122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444};


        return *upper_bound(begin(beautifulNums), end(beautifulNums), n) ;
    }
};