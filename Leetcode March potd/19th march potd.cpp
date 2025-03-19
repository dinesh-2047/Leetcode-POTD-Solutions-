/*
Problem: 3191. Minimum Operations to Make Binary Array Elements Equal to One
*/

class Solution {
    public:
        // Approach 1: Brute Force (Greedy)
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int op = 0; 
    
            for (int i = 0; i <= n - 3; i++) {
                if (nums[i] == 0) {
                    nums[i] = 1;
                    nums[i + 1] = !nums[i + 1];
                    nums[i + 2] = !nums[i + 2];
                    op++;
                }
            }
            
            auto lambda = [](int num) {
                return num == 1;
            };
    
            if (all_of(nums.begin(), nums.end(), lambda)) return op; 
            else return -1; 
        }
    };
    
    class Solution {
    public:
        // Approach 2: Sliding Window (Using Boolean Array)
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int k = 3;
            int flips = 0;
            int flipsCountFromPastFori = 0;
            vector<bool> isFlipped(n, false);
    
            for (int i = 0; i < n; i++) {
                if (i >= k && isFlipped[i - k]) {
                    flipsCountFromPastFori--;
                }
    
                if (flipsCountFromPastFori % 2 == nums[i]) { // Flip at index i
                    if (i + k > n) return -1; 
                    flipsCountFromPastFori++;
                    flips++;
                    isFlipped[i] = true;
                }
            }
            return flips;
        }
    };
    
    class Solution {
    public:
        // Approach 3: Sliding Window (In-Place Modification)
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int k = 3;
            int flips = 0;
            int flipsCountFromPastFori = 0;
    
            for (int i = 0; i < n; i++) {
                if (i >= k && nums[i - k] == 7) {
                    flipsCountFromPastFori--;
                }
    
                if (flipsCountFromPastFori % 2 == nums[i]) { // Flip at index i
                    if (i + k > n) return -1;
                    flipsCountFromPastFori++;
                    flips++;
                    nums[i] = 7;
                }
            }
            return flips;
        }
    };
    
    class Solution {
    public:
        // Approach 4: Sliding Window (Deque Optimization)
        // Time Complexity: O(N)
        // Space Complexity: O(K) 
        int k = 3;
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int flips = 0;
            deque<int> flipQue;
            int flipCountFromPastForCurri = 0;
    
            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    flipCountFromPastForCurri -= flipQue.front();
                    flipQue.pop_front();
                }
                
                if (flipCountFromPastForCurri % 2 == nums[i]) {
                    if (i + k > n) {
                        return -1;
                    }
                    flipCountFromPastForCurri++;
                    flipQue.push_back(1);
                    flips++;
                } else {
                    flipQue.push_back(0);
                }
            }
            return flips;
        }
    };