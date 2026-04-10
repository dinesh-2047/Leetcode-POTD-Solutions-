// 3740. Minimum Distance Between Three Equal Elements I

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , queue<int>>mp; 

        int result = INT_MAX;

        for(int i = 0 ; i  < n; i++){
            mp[nums[i]].push(i);
            if(mp[nums[i]].size() < 3) continue; 
            auto &q = mp[nums[i]];
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            int z = q.front();
            q.pop();

           result = min(result, abs(x-y) + abs(y-z) + abs(z-x));
           q.push(y);
           q.push(z);

        }
        return result == INT_MAX ? -1 : result; 

    }
};