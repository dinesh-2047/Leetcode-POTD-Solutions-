// 865. Smallest Subtree with all the Deepest Nodes


// Approach 1

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
class Solution {
public:
vector<TreeNode* > findLeaf(TreeNode* root){
    if(!root) return {};

    queue<TreeNode*>q; 
    q.push(root);
    vector<TreeNode*>leaf;

    while(!q.empty()){
        int n = q.size();
        vector<TreeNode* >l; 
        while(n--){
            auto curr = q.front();
            q.pop();
            l.push_back(curr);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        leaf = l; 

    }
    return leaf; 
}

TreeNode* LCA(TreeNode* root , TreeNode* a, TreeNode* b){
    if(!root) return nullptr; 

    if(root == a || root == b) return root; 

    TreeNode* left = LCA(root->left, a , b);
    TreeNode* right = LCA(root->right , a , b);

    if(left && right) return root; 

    return left != nullptr ? left  : right ; 
}

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode* >q; 

        vector<TreeNode*>leaf = findLeaf(root);

        TreeNode *a = leaf[0];
        TreeNode *b = leaf[leaf.size()-1];

       cout<<a->val<<" "<<b->val;

        return LCA(root , a , b);
    }
};





//approach 2 
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
class Solution {
public:
unordered_map<int , int>mp; 
int maxDepth; 
void depth(TreeNode* root, int d){
    if(root == nullptr) return ; 

    mp[root->val] = d; 
    maxDepth = max(maxDepth , d);
    depth(root->left, d + 1);
    depth(root->right , d + 1);
}

TreeNode* LCA(TreeNode* root){
    if(root == nullptr || mp[root->val] == maxDepth) return root; 

    TreeNode* l = LCA(root->left);
    TreeNode* r = LCA(root->right);

    if(l && r) return root; 
    return l != nullptr ? l : r;
}


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = 0;
        depth(root, 0);

        return LCA(root); 
    }
};




//Approach  3
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
class Solution {
public:
pair<int , TreeNode*> solve(TreeNode* root){
    if(root == nullptr){
        return {0, nullptr};
    }

     auto l = solve(root->left);
    auto r = solve(root->right);

    if(l.first == r.first){
        return {l.first + 1, root };
    }
    if(l.first > r.first){
        return {l.first + 1, l.second};
    }
    else{
        return {r.first + 1, r.second};
    }
    

    
}

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second; 
    }
};