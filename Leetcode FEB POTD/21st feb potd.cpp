// 1261. Find Elements in a Contaminated Binary Tree


// Approach 1 using bfs 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    public:
    unordered_set<int>st; 
        FindElements(TreeNode* root) {
           root->val = 0;
    
           queue<TreeNode*>q; 
    
           q.push(root);
            
    
           while(!q.empty()){
            int n = q.size();
    
            while(n--){
                auto curr = q.front();
                q.pop();
    
                st.insert(curr->val);
                
    
                if(curr->left) {
                    curr->left->val = 2*curr->val+1;
                    q.push(curr->left);
                }
    
                if(curr->right) {
                    curr->right->val  = 2*curr->val + 2;
                    q.push(curr->right);
                }
            }
           }
    
    
        }
        
        bool find(int target) {
            if(st.count(target)) return true; 
            else return false; 
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */



    // Approach 2 using dfs

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    public:
    unordered_set<int>st; 
    void dfs(TreeNode* root, int x ){
        if(!root) return ; 
        root->val =x;
        st.insert(x);
        dfs(root->left, 2*x+1);
        dfs(root->right, 2*x+2);
    }
    
        FindElements(TreeNode* root) {
         dfs(root , 0 );
    
        }
        
        bool find(int target) {
            if(st.count(target)) return true; 
            else return false; 
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */