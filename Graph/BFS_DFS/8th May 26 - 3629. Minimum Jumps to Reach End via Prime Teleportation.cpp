// 3629. Minimum Jumps to Reach End via Prime Teleportation


class Solution {
public:
vector<bool> isPrime; 
unordered_map<int , vector<int>> mp ; // nums -> indices
int maxi ; 
void sieve(){
    isPrime.assign(maxi + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for(int i = 2; i * i <= maxi; i++){
        if(isPrime[i]){
            for(int j = i * i ; j <= maxi; j+=i){
                isPrime[j] = false; 
            }
        }
    }
}

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        maxi = *max_element(begin(nums), end(nums));
        sieve();
        
        queue<int> q; 
        q.push(0);
        vector<bool> visited(n , false);
        visited[0] = true; 
        unordered_set<int>seen; 
        

        int result = 0; 

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto i = q.front();
                q.pop();

                if(i == n - 1) return result; 

                if(i + 1 < n && !visited[i + 1]){
                 visited[i + 1] = true;
                 q.push( i + 1);
                 
                }

                if(i - 1 >= 0  && !visited[i - 1]){
                    visited[i - 1] = true; 
                     q.push(i-1);
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) continue; 

                for(int j = nums[i] ; j <= maxi ; j+=nums[i]){
                    if(!mp.count(j)) continue; 

                    for(auto &k : mp[j]){
                        if(!visited[k]){
                            visited[k] = true; 
                            q.push(k);
                        }
                    }
                }
                seen.insert(nums[i]);

            }
            result++;

        }
        return result; 
        
    }
};