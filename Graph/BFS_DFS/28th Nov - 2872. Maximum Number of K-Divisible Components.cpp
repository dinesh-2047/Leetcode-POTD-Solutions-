// 2872. Maximum Number of K-Divisible Components


class Solution {
public:
    int dfs(int node, int parent, unordered_map<int, list<int>>& adj,
            vector<int>& values, int& result, int sum, int& k) {

        sum = values[node];

        for (auto& nbr : adj[node]) {
            if (nbr == parent)
                continue;
            sum = (sum + dfs(nbr, node, adj, values, result, sum, k)) % k;
        }

        sum = sum % k;
        if (!sum)
            result++;

        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        unordered_map<int, list<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = 0;

        dfs(0, -1, adj, values, result, 0, k);

        return result;
    }
};