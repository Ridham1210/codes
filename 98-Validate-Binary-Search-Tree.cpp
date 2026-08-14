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
    bool isbst(TreeNode* root, long long left, long long right){
        if(!root) return true;
        if((long long)root->val >= right || (long long)root->val <= left) return false;
        return (isbst(root->left, left, root->val) && isbst(root->right, root->val, right));
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isbst(root, LLONG_MIN , LLONG_MAX);
    }
};