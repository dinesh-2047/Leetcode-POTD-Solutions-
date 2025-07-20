// 1948. Delete Duplicate Folders in System

/*

✨ LeetCode POTD: Delete Duplicate Folders in System (1948)

⁉️ Problem Statement:
🔸 Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder.
🔸 Two folders (not necessarily on the same level) are identical if they contain the same non‑empty set of identical subfolders and underlying subfolder structure.
🔸 Mark all such duplicate folders and all their subfolders for deletion.
🔸 The file system deletes them once and returns the remaining folder paths in any order. 


📝 A folder is considered a duplicate if its entire subfolder structure — names and hierarchy — exactly matches another, even if located under a different parent.

🔎 Approach I Used:

1️⃣ Trie + Structural Encoding of Subfolders

✔️ Step 1: Building the Trie
• Defined a TrieNode structure with folder name, encoded subfolder string, and children map.
• Inserted every input path into the Trie representing the folder hierarchy.

✔️ Step 2: Encoding Subfolder Structure
• Using a post-order DFS, computed a unique structural encoding string for each folder’s subfolders.
• Format: "(a(x)(y))(b(z))", ensuring identical structures generate identical encodings.

✔️ Step 3: Detecting Duplicates
• Used an unordered map to count occurrences of each encoding.
• Any encoding with frequency >1 flagged its corresponding folders as duplicates.

✔️ Step 4: Removing Duplicate Subfolders
• Performed a second DFS to remove every child whose encoding occurred more than once — effectively deleting entire duplicate subfolder groups.

✔️ Step 5: Constructing the Result
• Ran a final DFS on the cleaned Trie to collect all remaining folder paths into the result.

🧠 Core Techniques Used:
• Trie Data Structure
• Post-Order DFS
• Structural Encoding of Subfolders
• HashMap Frequency Counting
• Recursive Traversals for Cleanup & Output

*/


//Code 
class Solution {
public:
struct TrieNode{
    string val; 
    string subFolder ; 
    unordered_map<string , TrieNode*> children; 
};

TrieNode* getNode(string val){
    TrieNode* temp = new TrieNode();
    temp->val = val; 
    temp->subFolder = "";
    return temp ; 
}

void insert(TrieNode* root,  vector<string> &path ){
         for(auto &folder : path){
                 if(!root->children.count(folder)){
                    root->children[folder] = getNode(folder); 
                 }
                  root = root->children[folder];
         }
        
}


string populateNodes(TrieNode* root , unordered_map<string , int> &subFolderMp ){
    vector<pair<string , string>>subFolderPaths;
          for(auto &[childName, child] : root->children){
               string subFolderResult = populateNodes(child, subFolderMp);
               subFolderPaths.push_back({childName, subFolderResult});
          }

          sort(subFolderPaths.begin(), subFolderPaths.end() );

          string completePath =  "";

          for(auto &[childName , childPath] : subFolderPaths){
                 completePath += "(" + childName  + childPath + ")";
          }

          root->subFolder = completePath; 

          if(!completePath.empty()){
                subFolderMp[completePath]++;
          }

          return completePath;
}


void removeDuplicates(TrieNode* root,unordered_map<string , int> &subFolderMp ){
    for(auto it = root->children.begin(); it!= root->children.end(); ){
        string childName = it->first; 
              TrieNode* child = it->second; 
              if(!child->subFolder.empty() && subFolderMp[child->subFolder] >  1){
                 it=  root->children.erase(it);
              }
              else{
                removeDuplicates(child, subFolderMp);
                it++;
              }
    }  
}

void buildResult(TrieNode* root , vector<string> &path, vector<vector<string>> &result){
    for(auto &[childName , child] : root->children){
        path.push_back(childName); 
        result.push_back(path);
        buildResult(child , path , result);
        path.pop_back();
    }
}


    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = getNode("/");
       
        // construct trie 
        for(auto &path : paths){
            insert(root, path); 
        }

        unordered_map<string , int>subFolderMp; 
        populateNodes(root, subFolderMp);


        removeDuplicates(root, subFolderMp);

        vector<vector<string>>result; 
        vector<string>path ; 

        buildResult(root, path , result);

        return result; 

    }
};