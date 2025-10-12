// 3539. Find Sum of Array Product of Magical Sequences

// Approach 1 
#define ll long long 
class Solution {
public:
int n; 
int mod = 1e9 + 7 ; 
ll solve(int m , int k , vector<int> &nums , int sum , int count ){
    if(count == m ){
        if(__builtin_popcount(sum) == k ){
            return 1; 
        }
        else return 0 ; 
    }

    ll totalSum = 0 ; 
    for(int i = 0 ; i < n ; i++ ){
        ll nSum = sum + (1LL << i);
        ll product = (nums[i] * solve(m , k , nums, nSum , count + 1))%mod;
        totalSum = (totalSum + product)%mod; 
    }
    return totalSum ; 
}
    int magicalSum(int m, int k, vector<int>& nums) {
        n =  nums.size();
        return solve(m , k , nums , 0, 0);
    }
};




//Approach 2 
#define ll long long 
class Solution {
public:
int n; 
int mod = 1e9 + 7 ; 
unordered_map<string  ,int>mp ; 
ll solve(int m , int k , vector<int> &nums , int sum , int count ){
    if(count == m ){
        if(__builtin_popcount(sum) == k ){
            return 1; 
        }
        else return 0 ; 
    }

    string key = to_string(sum) + "_" + to_string(count);
    if(mp.count(key)){
        return mp[key];
    }

    ll totalSum = 0 ; 
    for(int i = 0 ; i < n ; i++ ){
        ll nSum = sum + (1LL << i);
        ll product = (nums[i] * solve(m , k , nums, nSum , count + 1))%mod;
        totalSum = (totalSum + product)%mod; 
    }
    return mp[key] =  totalSum ; 
}
    int magicalSum(int m, int k, vector<int>& nums) {
        n =  nums.size();
        return solve(m , k , nums , 0, 0);
    }
};



//Approach 3 
#define ll long long 
class Solution {
public:
int n; 
int mod = 1e9 + 7 ; 
map<tuple<ll, int , int , int>, ll>dp ; 
vector<ll>fact; 
vector<ll>invFact; 
ll findPower(ll a , ll b){
    if(b == 0){
        return 1; 
    }

    ll half = findPower(a , b/2);
    ll result = (half * half) %mod; 

    if(b%2 == 1){
        result = (result * a)%mod; 
    }
    return result; 
}

ll nCr(int n , int r){
    return (((fact[n] * invFact[r])%mod) * invFact[n-r])%mod; 
}

ll solve(int m , int k , vector<int> &nums , int binarySum , int i ){
    auto key = make_tuple(binarySum , m , k , i);
    
    if(dp.count(key)){
        return dp[key];
    }

    if(m == 0 && __builtin_popcount(binarySum) == k ) {
        return 1; 
    }
    if(m == 0 || i >= n ){
        return 0; 
    }

    ll totalSum = 0 ; 
    totalSum = (totalSum + solve(m , k - (binarySum & 1), nums, (binarySum >> 1),i +1 )) %mod; 

    for(int freq = 1 ; freq <= m ; freq++){
        ll newBinarySum = binarySum + freq; 
        ll product = solve(m - freq, k - (newBinarySum & 1), nums, (newBinarySum >> 1), i + 1); 

        product = (findPower(nums[i], freq)%mod * product %mod)%mod; 
        product = (product * nCr(m , freq))%mod; 
        totalSum = (totalSum + product )%mod; 
    }
    return dp[key] = totalSum ; 
}
    int magicalSum(int m, int k, vector<int>& nums) {
        n =  nums.size();
        fact.assign(m + 1, 1);
        invFact.assign(m + 1, 1);

        for(int i = 2; i <= m; i++){
            fact[i] = (fact[i-1] * i )%mod; 
        }

        for(int i = 0 ; i <= m ; i++){
            invFact[i] = findPower(fact[i], mod-2);
        }

        return solve(m , k , nums , 0, 0);
    }
};