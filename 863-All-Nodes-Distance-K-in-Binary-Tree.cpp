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
    void findparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> atdistance(TreeNode* target,
                           unordered_map<TreeNode*, TreeNode*>& mp, int k) {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int level = 0;
        while (!q.empty()) {

            if (level++ == k)
                break;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (mp.count(curr) && visited.find(mp[curr]) == visited.end()) {
                    visited.insert(mp[curr]);
                    q.push(mp[curr]);
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        findparent(root, mp);
        return atdistance(target, mp, k);
    }
};