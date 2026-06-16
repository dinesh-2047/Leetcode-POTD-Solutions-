// 3612. Process String with Special Operations I

class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(auto &ch : s){
            if(ch == '*'){
                if(!result.empty()) result.pop_back();
            }
            else if(ch == '#'){
                result += result; 
            }
            else if (ch == '%'){
                reverse(begin(result), end(result));
            }
            else result += ch; 
        }
        return result; 
    }
};