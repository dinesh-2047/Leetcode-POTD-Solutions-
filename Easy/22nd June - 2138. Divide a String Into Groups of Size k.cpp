// 2138. Divide a String Into Groups of Size k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string>result; 

        int i = 0 ; 

        while(i < n ){
            int j = i + k -1; 
              if(i+k-1 >=n){
                j = n-1;
              }

              string str = s.substr(i , j-i+1);

              if(j-i + 1 < k ){
                int remain  = k - (j- i +1);
                str += string(remain, fill);
              }
              result.push_back(str);
              i+=k;
        }
        return result; 
    }
};