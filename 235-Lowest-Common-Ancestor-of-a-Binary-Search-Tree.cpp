/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int mini = min(p->val,q->val);
        int maxi = mini == p->val ? q->val : p->val;
        while(root){
        if(root->val <= maxi && root->val >= mini) return root;
        else if(root->val > maxi) root = root->left;
        else if(root->val < mini) root = root->right;}
        return root;
    }
};