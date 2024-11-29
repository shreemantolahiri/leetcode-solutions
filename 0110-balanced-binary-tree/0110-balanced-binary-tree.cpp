/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(right - left) > 1)
            ans = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);

        return ans;
    }
};