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
    void frompreorder(int va, TreeNode* root){
        TreeNode* prev;
        TreeNode* newnode = new TreeNode(va);
        while(root){
        prev = root;
        if(va < root->val) root = root->left;
        else if(va > root->val) root = root->right;
        }
        if(prev->val > va) prev->left = newnode;
        else prev->right = newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            frompreorder(preorder[i], root);
        }
        return root;
    }
};