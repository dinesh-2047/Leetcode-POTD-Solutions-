// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        stack<char> st; 

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                bool v = true; 
                while(!st.empty() && st.top() != '('){
                    if(st.top() == '[' || st.top() == '{') {
                        v = false; 
                        break; 
                    }
                    st.pop();
                }
                if(!v || st.empty()) return false; 
                else st.pop();
            }
            else if(s[i] == '}'){
                bool v = true; 
                while(!st.empty() && st.top() != '{'){
                    if(st.top() == '(' || st.top() == '[') {
                        v = false; 
                        break; 
                    }
                    st.pop();
                }
                if(!v || st.empty()) return false; 
                else st.pop();
            }
            else if(s[i] == ']'){
                bool v = true; 
                while(!st.empty() && st.top() != '['){
                    if(st.top() == '{' || st.top() == '(') {
                        v = false; 
                        break; 
                    }
                    st.pop();
                }
                if(!v || st.empty()) return false; 
                else st.pop();
            }
            
        }
    
        return st.empty(); 
    }
};