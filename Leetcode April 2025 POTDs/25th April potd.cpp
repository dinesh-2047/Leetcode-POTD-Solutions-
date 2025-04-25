// 2845. Count of Interesting Subarrays

//Approach (Using same concept as Leetcode - 974) - cumulative sum and modulo property
//T.C : O(n)
//S.C : O(n)
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
            int n = nums.size();
    
            unordered_map<int, long long> mp; //remainder -> count
            long long sum = 0; //sum will be equal to cnt of those elements % m == k
    
            long long result = 0;
    
            mp[0] = 1;
            for(int i = 0; i < n; i++) {
                if(nums[i] % m == k)
                    sum += 1;
    
                int r1 = sum%m;
    
                int r2 = (r1 - k + m) % m;
    
                result += mp[r2];
                mp[r1]++;
            }
    
            return result;
    
        }
    };
    