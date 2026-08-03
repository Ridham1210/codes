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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        if(!root) return level;
        TreeNode* curr = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            for(int i=0; i<size; i++){
            curr = q.front();
            q.pop();
            if(curr) {ans.push_back(curr->val);}
            if(curr &&(curr -> left)){
                q.push(curr->left);
            }
            if(curr && (curr->right)){
                q.push(curr->right);
            }
            }
            level.push_back(ans);
        }
        return level;
    }
};