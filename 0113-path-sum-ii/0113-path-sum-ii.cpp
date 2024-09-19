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
    vector<vector<int>> res;
    void solve(TreeNode* root, int targetSum, vector<int> temp){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            //leaf node
            if(targetSum==root->val){
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }
            temp.push_back(root->val);
            //go left or right
            solve(root->left,targetSum-root->val,temp);
            solve(root->right,targetSum-root->val,temp);

            temp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum,temp);

        return res;
    }
};