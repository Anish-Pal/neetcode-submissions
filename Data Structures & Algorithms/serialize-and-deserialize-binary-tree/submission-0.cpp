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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        queue<TreeNode*>q;
        string ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr){
                ans += "null,";
            }
            else{
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        stringstream s(data);
        string a;
        getline(s , a , ',');
        TreeNode* root = new TreeNode(stoi(a));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s, a , ',');
            if(a == "null") node->left = nullptr;
            else{
                node->left = new TreeNode(stoi(a));
                q.push(node->left);
            }
            getline(s , a , ',');
            if(a == "null") node->right = nullptr;
            else{
                node->right = new TreeNode(stoi(a));
                q.push(node->right);
            }
        }
        return root;
    }
};
