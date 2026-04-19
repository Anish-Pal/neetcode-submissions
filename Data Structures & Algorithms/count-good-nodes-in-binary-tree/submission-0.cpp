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
    int goodNodes(TreeNode* root) {
        int max = 0;
        dfs(root , root->val , max);
        return max;
    }
    void dfs(TreeNode* root , int max_so_far , int &count){
        if(root == nullptr) return;
        if(root->val >= max_so_far) count++;
        max_so_far = max(root->val , max_so_far);
        dfs(root->left , max_so_far , count);
        dfs(root->right , max_so_far , count);
    }
};
