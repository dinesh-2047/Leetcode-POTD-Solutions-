// 2265. Count Nodes Equal to Average of Subtree


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
int result = 0; 
pair<int , int> solve(TreeNode* root){
    if(!root) return {0, 0};

    auto l = solve(root->left);
    auto r = solve(root->right);

    int sum = root->val + l.first + r.first; 
    int cnt = 1 + l.second + r.second; 

    if(root->val == sum/cnt){
        result++;
    }
    return {sum , cnt};
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }
};