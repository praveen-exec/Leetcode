
class Solution {
public:
    int solve(TreeNode* root, int& result) {

        if(root == NULL)
            return 0;

        // height of left and right subtrees
        int left  = solve(root->left, result);
        int right = solve(root->right, result);

        // Calculate diameter passing through current node
        result = max(result, left + right);

        // height of current subtree (in nodes)
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int result = INT_MIN;
        solve(root, result);

        return result;
    }
};
