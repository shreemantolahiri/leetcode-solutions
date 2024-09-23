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
    bool pruneBTree(TreeNode* &root){
        if(root==NULL) return false;


        //check it's left child
        bool left=pruneBTree(root->left);
        bool right=pruneBTree(root->right);

        if(left==false) root->left=NULL;
        if(right==false) root->right=NULL;

        if(root->val==1) return true;
        else return (left || right || false);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return root;
        if(pruneBTree(root)==false) return NULL;
        return root;
    }
};