
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;

        if (root == NULL)
            return ans;

        q.push(root);

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode* t = q.front();
                q.pop();

                // Last node of every level
                if (i == qsize - 1)
                    ans.push_back(t->val);

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }
        }

        return ans;
    }
};
