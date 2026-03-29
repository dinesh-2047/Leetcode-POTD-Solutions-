// 2839. Check if Strings Can be Made Equal With Operations I

class Solution {
public:
bool solve(string a, string b){
    bool swap0 = false; 
    bool swap1 = false; 
    if(a[0] != b[0]){
        if(b[2] != a[0] || a[2] != b[0]) return false; 
        swap0 = true; 
    }

    if(a[1] != b[1]){
        if(b[3] != a[1] || a[3] != b[1]) return false; 
        swap1 = true; 
    }

   if(!swap0 && a[2] != b[2]) return false; 
   if(!swap1 && a[3] != b[3]) return false; 

   return true; 
}

    bool canBeEqual(string s1, string s2) {
        if(s1 == s2)  return true; 
        return solve(s1, s2) ;
    }
};