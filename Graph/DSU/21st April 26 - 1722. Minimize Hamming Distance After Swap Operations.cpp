// 1722. Minimize Hamming Distance After Swap Operations


class Solution {
public:
vector<int> parent;
vector<int> rank ; 
int find(int x){
    if(parent[x] == x) return x; 
    return parent[x] = find(parent[x]);
}

void Union(int x , int y){
    int parent_x = find(x);
    int parent_y = find(y);

    if(parent_x == parent_y)  return ; 

    if(rank[parent_x] > rank[parent_y]){
        parent[parent_y] = parent_x; 
    }
    else if(rank[parent_x] < rank[parent_y]){
        parent[parent_x] = parent_y;
    }
    else {
        parent[parent_y] = parent_x; 
        rank[parent_x]++;
    }
}

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      int n = source.size();
       parent.resize(n);
       rank.resize(n, 0);
       for(int i = 0 ; i  < n; i++){
          parent[i] = i;
       }

       for(auto &as : allowedSwaps){
          int a = as[0];
          int b = as[1];

          Union(a, b);
       }

       unordered_map<int , unordered_map<int , int>>mp; 

       for(int i = 0 ;i < n; i++){
          int root = find(i);
          mp[root][source[i]]++;
       }
        
        int result = 0 ; 
       for(int i =0 ; i  < n; i++){
           int root = find(i);

           if(mp[root][target[i]] > 0){
               mp[root][target[i]]--;
           }
           else result++;
       }

        return result; 
       
    }
};