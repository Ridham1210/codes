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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long  max_width = 0;
        while(!q.empty()){
            int size = q.size();
            int firstidx = 0, lastidx = 0;
            for(int i=0; i<size; i++){
                int parentidx = q.front().second;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i == 0) firstidx = parentidx;
                if(i == size-1) lastidx = parentidx;
                if(curr->left) q.push({curr->left, 2*1ll*parentidx + 1});
                if(curr->right) q.push({curr->right, 2*1ll*parentidx + 2});
            }
            max_width = max(max_width, (long long)lastidx-firstidx + 1);
        }
        return max_width;
    }
};