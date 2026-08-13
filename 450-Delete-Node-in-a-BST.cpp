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
    int find(TreeNode* root, int key){
        if(!root) return 0;
        int temp = 0;
        if(root->left){
            root = root->left;
        }
        while(root->right) root = root->right;
        temp = root->val;
        cout << temp << endl;
        root = nullptr;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            TreeNode* temp = root->left;
            while(temp->right) temp = temp->right;
            root->val = temp->val;
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }
};