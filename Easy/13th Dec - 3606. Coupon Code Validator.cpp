// 3606. Coupon Code Validator

class Solution {
public:
static bool cmp(pair<string , char > &a, pair<string , char> &b ){
    if(a.second == b.second){
        return a.first < b.first;  
    }
    return a.second < b.second; 
   
}


bool isValidCode(string code){
    if(code.empty()) return false; 
    for(auto &ch : code){
        if(!isalnum(ch) && ch != '_') return false; 
    }
    return true; 
}

bool isValidBusinessLine(string s){
    return s == "electronics" || s == "grocery" || s== "pharmacy" || s== "restaurant";
}

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string , char>>vec; 

        for(int i = 0 ; i < n; i++){
            if(isValidCode(code[i]) && isValidBusinessLine(businessLine[i]) && isActive[i]){
                vec.push_back({code[i], businessLine[i][0]});
            }
        }

        sort(begin(vec), end(vec), cmp);
       

        vector<string>result; 
        for(auto &v : vec){
            result.push_back(v.first);
        }
        return result; 

    }
};