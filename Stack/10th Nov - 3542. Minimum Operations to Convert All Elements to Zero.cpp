// 3542. Minimum Operations to Convert All Elements to Zero


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (nums[i] == 0)
                continue;

            if (st.empty() || nums[st.top()] < nums[i]) {
                result++;
                st.push(i);
            } else
                st.push(i);
        }
        return result;
    }
};