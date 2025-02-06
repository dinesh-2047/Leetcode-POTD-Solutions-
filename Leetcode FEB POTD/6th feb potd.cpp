// 1726. Tuple with Same Product

// Approach 1: Brute Force (TLE)
// Time Complexity: O(N^4)
// Space Complexity: O(1)
class Solution1 {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuplee = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (i != k && i != l && j != k && j != l) {
                            int product1 = nums[i] * nums[j];
                            int product2 = nums[k] * nums[l];
                            if (product1 == product2) {
                                tuplee++;
                            }
                        }
                    }
                }
            }
        }
        return (tuplee / 2) * 8;
    }
};

// Approach 2: Optimized Brute Force (TLE)
// Time Complexity: O(N^4)
// Space Complexity: O(1)
class Solution2 {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tupple = 0;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                for (int k = i + 1; k < j; k++) {
                    for (int l = j - 1; l > k; l--) {
                        int product1 = nums[i] * nums[j];
                        int product2 = nums[k] * nums[l];
                        if (product1 == product2) tupple++;
                    }
                }
            }
        }
        return tupple * 8;
    }
};

// Approach 3: Using Unordered Set (Optimized)
// Time Complexity: O(N^3)
// Space Complexity: O(N)
class Solution3 {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tupple = 0;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                unordered_set<int> s;
                int product = nums[i] * nums[j];
                for (int k = i + 1; k < j; k++) {
                    if (product % nums[k] == 0) {
                        int dvalue = product / nums[k];
                        if (s.count(dvalue)) {
                            tupple++;
                        }
                        s.insert(nums[k]);
                    }
                }
            }
        }
        return tupple * 8;
    }
};

// Approach 4: Using Hash Map (Most Optimized)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
class Solution4 {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // product -> frequency
        int tuples = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto& it : mp) {
            int freq = it.second;
            tuples += (freq * (freq - 1)) / 2; // freq C 2
        }
        return tuples * 8;
    }
};
