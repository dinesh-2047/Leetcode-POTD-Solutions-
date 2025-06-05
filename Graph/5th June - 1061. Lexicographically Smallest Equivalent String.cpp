// 1061. Lexicographically Smallest Equivalent String

/*
✨ LeetCode POTD: Lexicographically Smallest Equivalent String (1061) 🔤🔗

⁉️ Problem Statement:
🔸 You are given two strings s1 and s2 of the same length and a third string baseStr.
🔸 Characters s1[i] and s2[i] are considered equivalent.
🔸 This equivalence is transitive, symmetric, and reflexive.
🔸 You need to transform each character in baseStr to the lexicographically smallest equivalent character possible.

🔎 Approaches Used:

1️⃣ Set-Based Mapping and Merging
🔹 Maintain a map where each character is linked to its full equivalence set.
🔹 For each s1[i] and s2[i], merge their equivalence sets and assign the updated set to all characters involved.
🔹 For every character in baseStr, pick the smallest character in its equivalence set.
✅ Clear logic but can be inefficient due to repeated set copying and updates.

2️⃣ Disjoint Set Union (DSU / Union-Find)
🔹 Use a parent array of size 26 (for lowercase letters).
🔹 Perform union for each s1[i] and s2[i], attaching the larger character to the smaller one to maintain lexicographical order.
🔹 For each character in baseStr, find its root parent and replace it.
✅ Highly optimized approach using path compression.

3️⃣ DFS-Based Graph Traversal
🔹 Build a graph where each node is a character and edges represent equivalence from s1[i] and s2[i].
🔹 For each character in baseStr, use DFS to explore its connected component and return the smallest character.
✅ Recursive approach that respects all equivalence rules.

4️⃣ BFS-Based Graph Traversal
🔹 Similar to DFS, but replaces recursion with a queue.
🔹 For each character in baseStr, perform BFS to find all equivalent characters.
🔹 Replace the character with the lexicographically smallest one from the component.
✅ Iterative alternative with easier stack management.
*/






// Appraoch 1 
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();

        unordered_map<char , set<char>>mp ; 
    
       for(int i = 0 ; i <n; i++){
           char a = s1[i];
           char b = s2[i];

           set<char>merged;

           if(mp.count(a)) merged.insert(mp[a].begin(), mp[a].end());
           else merged.insert(a);

           if(mp.count(b)) merged.insert(mp[b].begin(), mp[b].end());
           else merged.insert(b);

           for(auto &c : merged){
             mp[c] = merged; 
           }
           
       }


       for(int i  = 0 ; i <baseStr.length(); i++){
          
          if(mp.find(baseStr[i])!=mp.end()){
             baseStr[i] = *mp[baseStr[i]].begin();
          }
       }

        return baseStr;
    }
};






//Approach 2
class Solution {
public:
vector<int>parent ; 

int find(int x){
    if(x==parent[x] ) return x; 

    return parent[x] = find(parent[x]);
}

void Union (int x , int y ){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent) return ; 

    if(x_parent > y_parent){
        parent[x_parent] = y_parent;
    }
    else parent[y_parent] = x_parent; 
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        parent.resize(26);

        for(int i = 0 ; i <26; i++){
            parent[i] = i;
        }

        for(int i = 0 ; i < n ; i++){
            Union(s1[i]-'a', s2[i]-'a');
        }

        for(int i = 0 ; i < baseStr.length(); i++){
            baseStr[i] = find(baseStr[i]-'a') + 'a';
        }
        return baseStr; 
    }
};






//Appproach 3 

class Solution {
public:
char dfs (unordered_map<char, list<char>> &adj, vector<bool> &visited, char curr){
     visited[curr-'a'] = true; 

     char minChar = curr; 

     for(auto &nbr : adj[curr]){
         if(!visited[nbr-'a']){
            minChar = min(minChar, dfs(adj , visited, nbr));
         }
     }
     return minChar ; 

}


    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char , list<char>>adj; 

         int n = s1.length();

         for(int i = 0 ; i <n; i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
         }
          
          string result = "";
         for(int i = 0 ; i < baseStr.length(); i++){
            vector<bool>visited(26, false);
            result.push_back(dfs(adj, visited, baseStr[i]));
         }
         return result; 
    }
};







//Approach 4 
class Solution {
public:
    char bfs(unordered_map<char, list<char>>& adj, char curr) {

        queue<char> q;
        q.push(curr);

        vector<bool> visited(26, false);
        visited[curr - 'a'] = true;

        char minChar = curr;

        while (!q.empty()) {
            char ch = q.front();
            q.pop();

            minChar = min(minChar, ch);
            for (auto& nbr : adj[ch]) {
                if (!visited[nbr - 'a']) {

                    visited[nbr - 'a'] = true;
                    q.push(nbr);
                }
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, list<char>> adj;

        int n = s1.length();

        for (int i = 0; i < n; i++) {
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result = "";
        for (int i = 0; i < baseStr.length(); i++) {
            result.push_back(bfs(adj, baseStr[i]));
        }
        return result;
    }
};