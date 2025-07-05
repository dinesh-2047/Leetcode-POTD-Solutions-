// 1394. Find Lucky Integer in an Array


// Appraoch 1 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

         int result = -1 ; 

         unordered_map<int , int>mp ; 

         for(int i= 0 ; i < n; i++){
            mp[arr[i]]++;
         }

         for(auto &[num , freq] : mp){
            if(num == freq){
                result = max(result , num);
            }
         }
         return result; 
    }
};






//Approach 2 


class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        vector<int> freq(501, 0);

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        int result = -1;

        for (int i = 0; i <= 500; i++) {
            if (freq[i] == 0)
                continue;
            if (freq[i] == i)
                result = max(i, result);
        }

        return result;
    }
};







//Approach 3 -> Inplace using bit masking the first 16 bit store freq of number and secnod 16 bit store number 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        

        for(int  &num :arr){

            int val = {num & 65535};

            if(val <= n ){
                arr[val-1] += (1<<16);
            }
        }

        for(int val = n ; val >=1; val--){
            if((arr[val-1] >> 16) == val) return val; 
         }
           return -1; 
    }
};