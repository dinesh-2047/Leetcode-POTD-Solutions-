// 3174. Clear Digits


// extra my brute force appraoch 
class Solution {
    public:
        string clearDigits(string s) {
            int n   = s.length();
    
            vector<int>v(n);
            
            for(int i =  n -1 ;  i>=0 ; i--){
                if(isdigit(s[i]) && v[i] != -1) {
                    v[i] = -1;
                    for(int j =  i - 1 ; j>=0 ; j--){
                        cout<<s[j]<<" ";
                        if(isalpha(s[j]) && v[j]!=-1){ 
                            v[j] = -1;
                        break;
                        }
                    }
                }
            }
    
            string ans = "";
    
            for(int i = 0 ; i<n; i++){
                if(v[i]!=-1) {
                    ans+=s[i];
                }
            }
            return ans;
    
        }
    };



//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public:
        string clearDigits(string s) {
            int i = 0;
    
            while (i < s.size()) {
                if (isdigit(s[i])) {
    
                    s.erase(i, 1);
                    if (i > 0) {
                        s.erase(i - 1, 1);
                        i--;
                    }
                } else {
                    i++;
                }
            }
            return s;
        }
    };
    
    
    //Approach-2 (Using stack)
    //T.C : O(n)
    //S.C : O(n) for stack
    class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
    
            for(char &ch : s) {
                if(ch >= 'a' && ch <= 'z') {
                    st.push(ch);
                } else if(!st.empty()) {
                    st.pop();
                }
            }
    
            string result = "";
            while(!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
    
            reverse(begin(result), end(result));
    
            return result;
        }
    };
    
    
    //Approach-3 (Using result string to avoid reverse call)
    //T.C : O(n)
    //S.C : O(1)
    class Solution {
    public:
        string clearDigits(string s) {
            string result = "";
    
            for(char &ch : s) {
                if(ch >= 'a' && ch <= 'z') {
                    result.push_back(ch);
                } else if(!result.empty()) {
                    result.pop_back();
                }
            }
    
            return result;
        }
    };
    
    
    //Approach-4 (Solving inplace)
    //T.C : O(n)
    //S.C : O(1)
    class Solution {
    public:
        string clearDigits(string s) {
            int j = 0;
    
            for (int i = 0; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    j = max(j - 1, 0); //max used to avoid negative
                } else {
                    s[j] = s[i];
                    j++;
                }
            }
    
            s.resize(j);
            return s;
        }
    };