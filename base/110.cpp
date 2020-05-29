class Solution {
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
               (abs(height(root->left) - height(root->right)) <= 1);
    }
};
