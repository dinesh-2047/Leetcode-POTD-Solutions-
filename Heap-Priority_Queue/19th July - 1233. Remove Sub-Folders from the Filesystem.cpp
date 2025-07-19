// 1233. Remove Sub-Folders from the Filesystem/



// Approach 1 using set 
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        vector<string>result ; 
        unordered_set<string>st(folder.begin(), folder.end()); 

        for(int i = 0 ; i < n; i++){
            string curr = folder[i];
            bool isValid = false; 
           int lastSlashIdx = 0 ; 
           for(int j = 1 ; j < curr.length() ; j++){
            if(curr[j] =='/') lastSlashIdx = j;
         string currParent = curr.substr(0, lastSlashIdx);
            
             
            if(st.count(currParent)  ){
                 isValid = true; 
                 break; 
            }
           }
           if(!isValid){
              result.push_back(curr);
           }

        }
        return result; 
    }
};














//Approach 2 optimized 
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        sort(folder.begin(), folder.end());

        vector<string> result;

        result.push_back(folder[0]);

        for (int i = 1; i < n; i++) {
            string prev = result.back();

            string curr = folder[i];

            string substrCurr = curr.substr(0, prev.length());

            if (prev == substrCurr && curr[prev.length()] == '/') {
                continue;
            } else {
                result.push_back(curr);
            }
        }

        return result;
    }
};