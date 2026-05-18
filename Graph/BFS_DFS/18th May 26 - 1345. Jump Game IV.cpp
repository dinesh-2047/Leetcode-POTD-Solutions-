// 1345. Jump Game IV

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true; 
        int result = 0;
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto curr = q.front();
                q.pop();

                if (curr == n - 1)
                    return result;
                if(curr - 1 >= 0 && !visited[curr-1]){
                    q.push(curr-1);
                    visited[curr- 1] = true; 
                }
                if(curr + 1 < n  && !visited[curr+1]){
                    q.push(curr+1);
                    visited[curr+ 1] = true; 
                }
                for (auto& nbr : mp[arr[curr]]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
                mp.erase(arr[curr]);
            }
            result++;
        }
        return result;
    }
};