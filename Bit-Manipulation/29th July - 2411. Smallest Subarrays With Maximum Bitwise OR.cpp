// 2411. Smallest Subarrays With Maximum Bitwise OR

//Approach 1 using sliding window  + bit manipulation

class Solution {
public:
    vector<int> bitFreq;
    void add(int num) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitFreq[i]++;
            }
        }
    }

    void remove(int num) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitFreq[i]--;
            }
        }
    }

    int getCurrOr() {
        int currOR = 0;
        for (int i = 0; i < 32; i++) {
            if (bitFreq[i] > 0) {
                currOR |= (1 << i);
            }
        }
        return currOR;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        bitFreq.resize(32, 0);
        vector<int>maxOr(n);
        int maxOrr = 0; 
        for(int i = n-1 ; i >=0 ;i--){
            maxOrr |= nums[i];
            maxOr[i] = maxOrr; 
        }

      

        vector<int> result(n, 1);

        int i = 0;
        int j = 0;

        while (j < n) {
            add(nums[j]);
            int currOr = getCurrOr();

            while(i <= j && currOr == maxOr[i]){
                
                result[i] = (j- i + 1);
                remove(nums[i]);
                currOr = getCurrOr();
                i++;
            }
            j++;
        }

        return result; 
    }
};








//Approach 2 using bit manipulation
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int>setBitIdx(32, -1);
        vector<int>result(n); 


        for(int i = n-1; i >=0 ;i--){
            int endIdx = i ; 

            for(int j = 0 ; j < 32 ;j++){
                if(!(nums[i] & (1 << j))){
                    if(setBitIdx[j]!=-1){
                        endIdx = max(endIdx, setBitIdx[j]);
                    }
                }
                else{
                    setBitIdx[j] = i ; 
                }
            }
            result[i] = endIdx - i  +1; 
        }
        return result; 
    }
};