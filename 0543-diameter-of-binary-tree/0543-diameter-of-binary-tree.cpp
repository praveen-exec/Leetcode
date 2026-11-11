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
    int height(TreeNode* root) {
        if(root == NULL)
            return -1;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        // Height of left + height of right + 2 edges
        int x = height(root->left) + height(root->right) + 2;

        int y = diameterOfBinaryTree(root->left);
        int z = diameterOfBinaryTree(root->right);

        return max(x, max(y, z));
    }    
};