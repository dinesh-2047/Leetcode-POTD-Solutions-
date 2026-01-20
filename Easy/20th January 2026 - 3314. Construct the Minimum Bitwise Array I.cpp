// 3314. Construct the Minimum Bitwise Array I

class Solution {
public:
int getX(int n ){
    string binary = bitset<32>(n).to_string();
    int cnt = 0 ; 
    for(int i = binary.length() ; i >= 0 ; i--){
          if(binary[i] == '0'){
            binary[i+1] = '0';
            break; 
          }
       
    }

    int dec = stoi(binary , nullptr, 2);

    return dec; 
}

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>result(n);

        for(int i = 0 ; i  < n; i++){
           if(nums[i] == 2){
              result[i] = -1; 
              continue; 
           }
           else{
              int x = getX(nums[i]);
              result[i] = x; 
           }
        }
        return result; 
    }
};