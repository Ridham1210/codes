/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        bool ltr = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                int idx = ltr ? i : size-i-1;
                v[idx] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ltr = !ltr;
            ans.push_back(v);
        }
        return ans;
    }
};