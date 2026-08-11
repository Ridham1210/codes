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
    int width(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long max_width = 0;
        int min_idx = 0;
        while (!q.empty()) {
            int size = q.size();
            min_idx = min((long long)min_idx, q.front().second);
            int first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                int parentidx = q.front().second - min_idx;
                TreeNode* curr = q.front().first;
                q.pop();
                if (i == 0)
                    first = parentidx;
                if (i == size-1)
                    last = parentidx;
                if (curr->left) {
                    q.push({curr->left, 2 *1ll* parentidx + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 *1ll* parentidx + 2});
                }
            }
            max_width = max(max_width, (long long)last - first + 1);
        }
        return max_width;
    }
    int widthOfBinaryTree(TreeNode* root) { return width(root); }
};