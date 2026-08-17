/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(!curr)
            {
                s.append("@,");
            }
            else{
                s.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        vector<int>v;
        int i=0;
        
        while(i<s.size())
        {
            string temp="";
            if(s[i]=='@'){v.push_back(1001);i++;}
            else{
                while(s[i]!=',')
                {
                    temp+=(s[i]);
                    i++;
                }
                v.push_back(stoi(temp));
            }
            i++;
        }
        if(v.empty())return nullptr;
        TreeNode* root=new TreeNode(v[0]);
        queue<TreeNode*>q;
        q.push(root);
        i=1;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(i<v.size())
            {
                if(v[i]==1001)node->left=nullptr;
                else {node->left=new TreeNode(v[i]);
                q.push(node->left);}
                i++;
            }
            if(i<v.size())
            {
                if(v[i]==1001)node->right=nullptr;
                else{ node->right=new TreeNode(v[i]);
                q.push(node->right);}
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));