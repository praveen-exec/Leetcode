class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans;

        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode* t = q.front();
                q.pop();

                // First node of every level
                if (i == 0)
                    ans = t->val;

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }
        }

        return ans;
    }
};