// 2401. Longest Nice Subarray


// Approach 1: Brute Force (Might give MLE for large inputs)
// Time Complexity: O(N^3), Space Complexity: O(1)
class Solution1 {
    public:
        bool isNice(vector<int>& nums, int i, int j) {
            int mask = 0;
            for (int k = i; k <= j; k++) {
                if ((mask & nums[k]) != 0) return false;
                mask = (mask | nums[k]);
            }
            return true;
        }
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size(), result = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (isNice(nums, i, j)) {
                        result = max(result, j - i + 1);
                    }
                }
            }
            return result;
        }
    };
    
    // Approach 2: Optimized Brute Force
    // Time Complexity: O(N^2), Space Complexity: O(1)
    class Solution2 {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size(), result = 0;
            for (int i = 0; i < n; i++) {
                int mask = 0;
                for (int j = i; j < n; j++) {
                    if ((mask & nums[j]) == 0) {
                        result = max(result, j - i + 1);
                        mask = (mask | nums[j]);
                    } else break;
                }
            }
            return result;
        }
    };
    
    // Approach 3: Sliding Window (Optimized)
    // Time Complexity: O(N), Space Complexity: O(1)
    class Solution3 {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size(), result = 0, i = 0, j = 0, mask = 0;
            while (j < n) {
                while ((mask & nums[j]) != 0) {
                    mask ^= nums[i];
                    i++;
                }
                result = max(result, j - i + 1);
                mask |= nums[j];
                j++;
            }
            return result;
        }
    };
    