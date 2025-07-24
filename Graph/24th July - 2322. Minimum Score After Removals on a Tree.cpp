// 2322. Minimum Score After Removals on a Tree

/*
✨ LeetCode POTD: Minimum Score After Removals on a Tree (2322) 🌲

⁉️ Problem Statement:
🔸 You're given a tree of n nodes where each node has a value.
🔸 You can remove any two edges such that the tree splits into 3 components.
🔸 For each component, calculate the XOR of all node values.
🔸 The score is defined as the difference between the maximum and minimum XOR values of these components.
🔸 Return the minimum possible score over all valid edge-removal choices.

🔎 Approach I Used:

1️⃣ DFS + Euler Tour + Subtree XORs
🔹 I performed a Depth-First Search (DFS) starting from node 0 to calculate the XOR of the entire subtree rooted at each node.
🔹 During this DFS, I also recorded the inTime and outTime of each node — this is a classic Euler Tour technique that helps determine if one node is an ancestor of another in constant time.
🔹 I then iterated over every pair of non-root nodes (u, v) to simulate the removal of the two edges leading to them.
🔹 For each pair, I handled 3 possible subtree relationships:
 • If one is an ancestor of the other
 • If the other is an ancestor of the first
 • If they are completely independent
🔹 Based on their relationship, I computed:
 • xor_a: subtree XOR of one node
 • xor_b: XOR of the remaining part of the other subtree
 • xor_c: total XOR of tree minus xor_a and xor_b
🔹 The score is max(xor_a, xor_b, xor_c) - min(...), and I kept track of the minimum across all valid combinations.
✅ This approach efficiently reduces the problem from a brute-force cut simulation to constant-time subtree math after a single DFS.

🔧 Complexity:
• Time: O(n²) — trying all pairs of edges (excluding root)
• Space: O(n) — for adjacency list, visited, in/out timestamps, and subtree XORs

🧠 Key Takeaway:
This problem shows how DFS, Euler Tour, and bitwise XOR math can combine to solve a tricky tree-partitioning problem.
Understanding ancestor relationships and breaking problems into clean cases is critical in tree algorithms.

*/


class Solution {
public:
void dfs(int node , vector<int> &nums, vector<int>  &subTreeXor, vector<bool> &visited, vector<int> &inTime , vector<int> &outTime , int &timer , unordered_map<int , list<int>> &adj){

    visited[node] =  true; 
    subTreeXor[node] = nums[node];
    inTime[node] = timer;
    timer++;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            dfs(nbr, nums, subTreeXor, visited, inTime, outTime, timer, adj );
            subTreeXor[node] ^= subTreeXor[nbr];
        } 
    }

    outTime[node] = timer; 
    timer++;
}

bool isAncestor(int u , int v, vector<int> &inTime, vector<int> &outTime){
    return inTime[v] >= inTime[u] && outTime[v] <= outTime[u]; 
}

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int , list<int>>adj; 
        
        for(auto &edge :edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>subTreeXor(n , 0);
        vector<int>inTime(n, 0);
        vector<int>outTime(n , 0);
        vector<bool>visited(n , 0);
        int timer = 0 ; 

        dfs(0, nums, subTreeXor , visited, inTime, outTime ,  timer , adj);
        int result = INT_MAX;

        for(int u= 1; u < n; u++){
            for( int v = u + 1; v < n; v++){
                
                int xor_a = 0;
                int xor_b = 0 ; 
                int xor_c = 0 ; 

                if(isAncestor(u, v, inTime, outTime)){
                    xor_a = subTreeXor[v];
                    xor_b = subTreeXor[v] ^ subTreeXor[u];
                    xor_c = subTreeXor[0] ^ xor_a ^ xor_b;
                 }
                else if(isAncestor(v, u, inTime , outTime)){
                    xor_a = subTreeXor[u];
                    xor_b = subTreeXor[v] ^ subTreeXor[u];
                    xor_c = subTreeXor[0] ^ xor_a ^ xor_b;
                }

                else {
                    xor_a = subTreeXor[u];
                    xor_b = subTreeXor[v] ;
                    xor_c = subTreeXor[0] ^ xor_a ^ xor_b;


                }

                result = min(result , max({xor_a, xor_b, xor_c}) - min({xor_a, xor_b, xor_c}));
            }
        }

        return result; 
    }
};