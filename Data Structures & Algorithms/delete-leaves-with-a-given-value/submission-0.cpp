class Solution {
public:
    void dfs(TreeNode*& root, int target) {
        if (!root) return;

        dfs(root->left, target);
        dfs(root->right, target);

        if (root->val == target &&
            root->left == nullptr &&
            root->right == nullptr) {
            delete root;
            root = nullptr;
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        return root;
    }
};