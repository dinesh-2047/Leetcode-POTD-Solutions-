// 1339. Maximum Product of Splitted Binary Tree

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
long long maxPro;
int totalSum; 
int mod = 1e9 + 7;
void getSum(TreeNode* root ){
    if(!root) return ; 

    getSum(root->left);
    totalSum = totalSum +  root->val; 
    getSum(root->right);
}

int solve(TreeNode* root){
    if(!root) return 0 ; 
 
    int leftSum = solve(root->left);
    int rightSum = solve(root->right);

    long long subTreeSum = root->val + leftSum + rightSum; 

    int remainSubTreeSum  = totalSum - subTreeSum; 
    maxPro = max(maxPro ,  subTreeSum * remainSubTreeSum);

    return subTreeSum; 
    
    
}

    int maxProduct(TreeNode* root) {
          totalSum = 0 ; 
         getSum(root);
          maxPro = 0 ; 
         solve(root);
         return  maxPro%mod; 
    }
};