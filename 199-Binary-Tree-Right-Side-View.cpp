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
    void preorder(TreeNode* root, int left, int right, map<int, vector<pair<int,int>>>& mp){
        if(!root) return;
        if(mp.find(left) == mp.end())
            mp[left].push_back({right, root->val});
        
        preorder(root->right, left+1, right+1, mp);
        preorder(root->left, left+1, right-1, mp);
        
    }
    vector<int> rightSideView(TreeNode* root) {
         map<int, vector<pair<int,int>>> mp;
        vector<int> ans;
        if(!root) return ans;
        preorder(root,0,0,mp);
        
        for(auto& it : mp){
            vector<pair<int,int>> v = it.second;
            ans.push_back(v[0].second);
        }
        return ans;
    }
};