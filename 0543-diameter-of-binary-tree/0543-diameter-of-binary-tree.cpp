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
private:
    int maxDiameter=0;
public:
    int solve(TreeNode* root){
        if(root==NULL) return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        maxDiameter=max(left+right,maxDiameter);

        return max(left,right)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);

        return maxDiameter;
    }
};