// 2948. Make Lexicographically Smallest Array by Swapping Elements

class Solution {
public:
vector<int> parent, rank ; 
int find(int x){
    if(parent[x] == x) return x; 
    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    int px = find(x);
    int py = find(y);

    if(px == py) return ; 

    if (rank[px] < rank[py]) {
        parent[px] = py;
    }
    else if (rank[px] > rank[py]) {
        parent[py] = px;
    }
    else {
        parent[py] = px;
        rank[px]++;
    }
}
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int , int>> vec(n); 
        for(int i = 0 ;i < n; i++){
            vec[i] = {nums[i], i};
        }
        sort(begin(vec), end(vec));

         
        parent.resize(n, 0);
        rank.resize(n , 0);
        for(int i = 0 ;i < n; i++){
            parent[i] = i; 
        }
         
        for(int i = 1 ; i  < n; i++){
             if(abs(vec[i].first - vec[i - 1].first) <= limit){
                Union(vec[i].second,vec[i - 1].second); 
             }
        }

        unordered_map<int , multiset<int> > mp ; 
        for(int i = 0 ; i < n; i++){
            mp[parent[i]].insert(nums[i]);
        }

        for(int i = 0 ;i < n; i++){
            nums[i] = *mp[parent[i]].begin();
            mp[parent[i]].erase(mp[parent[i]].begin());
        }

        return nums ;

    }
};