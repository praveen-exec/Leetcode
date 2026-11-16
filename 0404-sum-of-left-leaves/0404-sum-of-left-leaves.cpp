class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if (root == NULL)
            return 0;

        int sum = 0;

        // Is the left child a leaf?
        if (root->left &&
            root->left->left == NULL &&
            root->left->right == NULL) {

            sum += root->left->val;
        }

        // Calculate sums from both subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};