// 1622. Fancy Sequence



class Fancy {
public:
using ll = long long ; 
vector<ll> vec; 
ll add, mult; 
int mod = 1e9 + 7; 
ll power(ll a, ll b){
    if(b == 0 ) return 1; 
    ll half = power(a, b/2)%mod;
    ll result = (half * half)%mod; 

    if(b%2 == 1){
        result = (result * a)%mod; 
    }
    return result%mod; 
}


    Fancy() {
        add = 0 ; 
        mult = 1; 
    }
    
    void append(int val) {
         vec.push_back(((val - add) * power(mult, mod - 2)%mod + mod)%mod);
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
         add = (add * m )%mod; 
         mult = (mult * m )%mod;  
    }
    
    int getIndex(int idx) {
        if(vec.size() < (idx + 1)) return -1; 
        return (vec[idx] * mult + add)%mod; 
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */