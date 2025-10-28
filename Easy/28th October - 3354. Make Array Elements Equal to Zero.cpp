// 3354. Make Array Elements Equal to Zero


// Approach 1/
class Solution {
public:
int n; 
void moveInDirection(vector<int> &nums , char direction, int curr){
     while(curr < n && curr >= 0 ){
                if(nums[curr] == 0 ) {
                    if(direction == 'R'){
                        curr++;
                    }
                    else curr--;
                }
                else{
                    nums[curr]--; 
                    if(direction == 'R'){
                        direction ='L';
                        curr--;
                    }
                    else{
                        direction = 'R';
                        curr++;
                    }
                }
            }
}

bool isValid(vector<int> &nums){
      auto lambda = [](int num){
                return num == 0 ; 
             };
            if(all_of(begin(nums), end(nums), lambda)){
                return true; 
            }
            return false; 
}

    int countValidSelections(vector<int>& nums) {
         n = nums.size();
        int result = 0 ;
        for(int i = 0 ; i  < n; i++){
            if(nums[i] != 0 ) continue; 
            vector<int>temp = nums; 
            moveInDirection(temp , 'R', i);
            if(isValid(temp)){
                result++;
            }
            temp = nums ; 
            moveInDirection(temp, 'L', i);
             if(isValid(temp)){
                result++;
             }
        }
     return result; 
    }
};





//Approach 2 
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int result = 0 ;
        vector<int>pref(n , 0);
        vector<int>suff(n , 0);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + nums[i];
        }

        for(int i = n-2; i >= 0 ; i--){
            suff[i] = suff[i + 1] + nums[i];
        }

        for(int i = 0 ; i  < n; i++){
            if(nums[i]!=0 ) continue; 
            if(pref[i] == suff[i]){
                result+=2; 
            }
            else if(abs(pref[i] - suff[i]) == 1){
                result++;
            }
        }
        return result; 
    }
};




//Approach 3 
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        
        int result = 0 ; 
        int leftSum = 0 ; 
        int rightSum = sum ; 

        for(int i = 0 ; i  < n; i++){
            
            leftSum += nums[i];
            rightSum -= nums[i];
            if(nums[i] != 0 ) continue; 
            if(leftSum == rightSum) result += 2; 
            if(abs(leftSum - rightSum) == 1) result++;
        }
        return result; 
    }
};