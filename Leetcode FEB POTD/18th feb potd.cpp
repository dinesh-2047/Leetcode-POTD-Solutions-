// 2375. Construct Smallest Number From DI String

// Approach 1: Brute Force (Permutation Approach)
class Solution {
public:
    bool patternMatch(string &num, string &pattern) {
        // Check if the current permutation satisfies the pattern
        for (int i = 0; i < pattern.length(); i++) {
            // If pattern[i] is 'I', num[i] should be less than num[i+1]
            // If pattern[i] is 'D', num[i] should be greater than num[i+1]
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) || 
                (pattern[i] == 'D' && num[i] < num[i + 1])) 
                return false;
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";

        // Initialize the number string with numbers 1 to n+1
        for (int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0');
        }

        // Brute force: generate the next permutation until we find a valid sequence
        while (!patternMatch(num, pattern)) {
            next_permutation(num.begin(), num.end());
        }

        return num;
    }
    /*
    Time Complexity: O((n+1)! * n) 
    - Generating all permutations of n+1 digits takes (n+1)!
    - For each permutation, checking if the pattern is satisfied takes O(n) time.
    
    Space Complexity: O(n)
    - Storing the result string and other auxiliary variables.
    */
};

// Approach 2: Stack-Based Approach
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        stack<char> st;

        // Push digits from 1 to n+1 into the stack
        for (int i = 0; i <= n; i++) {
            st.push((i + 1) + '0');
            
            // When 'I' is encountered or we reach the end, pop and append the stack elements to the number
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    num += st.top();
                    st.pop();
                }
            }
        }
        return num;
    }
    /*
    Time Complexity: O(n)
    - We iterate over the pattern string once (O(n)) and perform stack operations (push and pop) which are O(n).
    
    Space Complexity: O(n)
    - The stack can store up to n elements, and we also store the result string.
    */
};

// Approach 3: String as Stack Approach
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        string st = "";  // String acting as a stack

        // Push digits from 1 to n+1 into the string stack
        for (int i = 0; i <= n; i++) {
            st.push_back((i + 1) + '0');
            
            // When 'I' is encountered or we reach the end, pop and append the string stack elements to the number
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    num += st.back();
                    st.pop_back();
                }
            }
        }
        return num;
    }
    /*
    Time Complexity: O(n)
    - We iterate over the pattern string once (O(n)) and perform string operations (push_back and pop_back) which are O(n).
    
    Space Complexity: O(n)
    - The string `st` can hold up to n elements, and the result string also holds up to n elements.
    */
};

// Approach 4: Backtracking Approach
class Solution {
public:
    int n;
    bool backtrack(string &pattern, string &num, string &path, vector<bool> &used, int i) {
        if (i == n + 1) {
            num = path;
            return true;
        }

        // Try placing each number (1 to n+1) in the sequence
        for (int d = 0; d <= n; d++) {
            if (used[d]) continue;  // Skip used digits

            // Ensure that the pattern is maintained for 'I' and 'D'
            if (i == 0 || 
                (pattern[i - 1] == 'I' && path.back() < (d + 1) + '0') || 
                (pattern[i - 1] == 'D' && path.back() > (d + 1) + '0')) {

                used[d] = true;
                path += (d + 1) + '0';

                // Recurse to the next digit
                if (backtrack(pattern, num, path, used, i + 1)) return true;

                used[d] = false;
                path.pop_back();
            }
        }
        return false;
    }

    string smallestNumber(string pattern) {
        n = pattern.length();
        string num = "";
        vector<bool> used(10, false);  // To track used digits
        string path = "";

        backtrack(pattern, num, path, used, 0);
        return num;
    }
    /*
    Time Complexity: O(n!)
    - The backtracking approach explores all possible valid sequences. The worst-case complexity is O(n!) since we are trying to place each number in the sequence.

    Space Complexity: O(n)
    - The recursion stack and auxiliary variables require O(n) space.
    */
};

