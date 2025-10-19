// 1625. Lexicographically Smallest String After Applying Operations


// Approach 1 using dfs
class Solution {
public:
int n ;
void solve(string &s, int a , int b , string &result , unordered_set<string> &visited){
    result = min(result , s);

    string temp = s; 
    for(int i = 1 ; i  < n; i+= 2){
         temp[i] = ( (temp[i] - '0') + a ) % 10 + '0';

    }
    if(!visited.count(temp)){
        visited.insert(temp);
        solve(temp , a , b , result , visited);
    }
     string rotated = s;
    rotate(begin(rotated), begin(rotated) + (n-b), end(rotated) );
    if(!visited.count(rotated)){
        visited.insert(rotated);
        solve(rotated, a, b, result , visited);
    }
}

    string findLexSmallestString(string s, int a, int b) {
         n = s.length();

        string result = s;
         unordered_set<string>visited; 
         visited.insert(s);
        solve(s, a , b , result , visited);

        return result; 


    }
};






//Approach 2 using bfs 
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();

         string result = s;
         unordered_set<string>visited; 
         visited.insert(s);
        
        queue<string>q; 
        q.push(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

         result = min(result , curr);

            string temp = curr; 
            for(int i = 1; i < n; i+=2){
                temp[i] = ((temp[i] -'0') + a)%10 + '0';
            }
            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }
            

            string rotated = curr;
            rotate(begin(rotated), begin(rotated) + (n - b), end(rotated));
            if(!visited.count(rotated)){
                visited.insert(rotated);
                q.push(rotated); 
            }
         
        }

        return result; 


    }
};