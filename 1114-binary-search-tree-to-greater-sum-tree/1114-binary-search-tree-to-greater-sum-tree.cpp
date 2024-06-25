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
    // Initialize sum to store the cumulative sum of node values
    int sum = 0;

    // Helper function to perform reverse in-order traversal
    void solve(TreeNode* &root) {
        if (root == NULL) return; // Base case: if the node is NULL, return

        // Recursively traverse the right subtree
        solve(root->right);

        // Update sum with the value of the current node
        sum += root->val;
        // Update the value of the current node with the cumulative sum
        root->val = sum;

        // Recursively traverse the left subtree
        solve(root->left);
    }

    // Function to convert BST to Greater Sum Tree
    TreeNode* bstToGst(TreeNode* root) {
        // Call the helper function to start the conversion
        solve(root);

        // Return the modified tree
        return root;
    }
};
