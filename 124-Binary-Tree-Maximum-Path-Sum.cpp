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
    int max_sum = INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;
        int ls = max(0,sum(root->left));
        int rs = max(0,sum(root->right));
        max_sum = max(max_sum, ls + rs +root->val);
        return (root->val + max(ls,rs));
    }
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        sum(root);
        return max_sum;
    }
};