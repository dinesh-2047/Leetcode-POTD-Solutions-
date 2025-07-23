// 1717. Maximum Score From Removing Substrings/]


// Approach 1
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();

        int result = 0 ; 
        stack<char>st; 
        
        if(y >  x){
        for(int i = 0 ;i <n; i++){
            char ch = s[i];
        

            if(!st.empty() && st.top() == 'b' && ch == 'a'){
                st.pop();
                result += y; 
            }
            else
            st.push(ch);
           
        }
        }
        else{
            for(int i = 0 ; i <n; i++){
            char ch = s[i];
            
           
            if(!st.empty() && st.top()=='a' && ch == 'b' ){
                st.pop();
                result += x;
            }
            else
            st.push(ch);
            }
        }
        
        string str = "";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());

        for(int i = 0 ; i < str.length(); i++){
            if(!st.empty() && st.top()=='a' && str[i] =='b'){
                result +=x; 
                st.pop();
            }
            else if(!st.empty() && st.top() == 'b' && str[i] == 'a'){
                st.pop();
                result += y ; 
            }
            else st.push(str[i]);
        }

              return result; 
    }
};




//Approach 2
class Solution {
public:
string removeStr(string s, string &removalStr){
    int n = s.length();
    int i = 0 ; 
    for(int j = 0 ; j < n; j++){
        s[i] = s[j];
          i++;
          if(i-2 >= 0 && s[i-1] == removalStr[1] && s[i-2] == removalStr[0]){
              i = i-2; 
          }
          
    }
    s.erase(s.begin() + i , s.end());
    cout<<s<<endl; 
    return s;
}


    int maximumGain(string s, int x, int y) {
        int n = s.length();
        
        int result = 0 ; 
        string firstPriority =  (x >= y ) ? "ab" : "ba";
        string secondPriority =  (x < y ) ? "ab" : "ba";

        
        string afterRemovalFirstPriority = removeStr(s, firstPriority);
        int L = n - afterRemovalFirstPriority.length();

        result += (L/2) * max(x, y); 

        string afterRemovalSecondPriority = removeStr(afterRemovalFirstPriority, secondPriority);
        int L2 = afterRemovalFirstPriority.length() -  afterRemovalSecondPriority.length();

        result += (L2/2) * min(x, y); 


        return result; 

    }
};