// 2206. Divide Array Into Equal Pairs


// Approach 1: Brute Force (Nested Loops) - O(N^2) Time, O(1) Space
class Solution1 {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size();
            if (n % 2 == 1) return false;
    
            int pairs = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] == nums[j] && nums[i] != -1) {
                        nums[j] = -1; // Mark as used
                        pairs++;
                        break;
                    }
                }
            }
            return pairs == n / 2;
        }
    };
    
    // Approach 2: Using HashMap Frequency Count - O(N) Time, O(N) Space
    class Solution2 {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size();
            if (n % 2 == 1) return false;
    
            unordered_map<int, int> freq;
            for (int num : nums) freq[num]++;
    
            for (auto it : freq) {
                if (it.second % 2 == 1) return false;
            }
            return true;
        }
    };
    
    // Approach 3: Sorting & Two-Pointer - O(N log N) Time, O(1) Space
    class Solution3 {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size();
            if (n % 2 == 1) return false;
    
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i += 2) {
                if (nums[i] != nums[i + 1]) return false;
            }
            return true;
        }
    };
    
    // Approach 4: Using Max Heap (Priority Queue) - O(N log N) Time, O(N) Space
    class Solution4 {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size();
            if (n % 2 == 1) return false;
    
            priority_queue<int> pq(nums.begin(), nums.end());
            while (!pq.empty()) {
                int first = pq.top(); pq.pop();
                int second = pq.top(); pq.pop();
                if (first != second) return false;
            }
            return true;
        }
    };
    
    // Approach 5: Using Frequency Array (Fixed size) - O(N) Time, O(1) Space
    class Solution5 {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> freq(501, 0);
            for (int num : nums) freq[num]++;
            
            for (int i = 0; i < 501; i++) {
                if (freq[i] % 2 == 1) return false;
            }
            return true;
        }
    };
    
    // Approach 6: Using HashSet for Pairing - O(N) Time, O(N) Space
    class Solution6 {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_set<int> st;
            int pairs = 0;
    
            for (int num : nums) {
                if (st.count(num)) {
                    pairs++;
                    st.erase(num);
                } else {
                    st.insert(num);
                }
            }
            return pairs == nums.size() / 2;
        }
    };
    
    // Approach 7: XOR Trick - O(N log N) Time, O(1) Space
    class Solution7 {
    public:
        bool divideArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); i += 2) {
                if ((nums[i] ^ nums[i - 1]) != 0) return false;
            }
            return true;
        }
    };
    
    // Approach 8: Boolean Array Trick - O(N) Time, O(1) Space
    class Solution8 {
    public:
        bool divideArray(vector<int>& nums) {
            vector<bool> paired(501, true);
            for (int num : nums) paired[num] = !paired[num];
            
            for (bool isPaired : paired) {
                if (!isPaired) return false;
            }
            return true;
        }
    };
    