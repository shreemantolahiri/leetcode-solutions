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
    int longestPath=0;
    int solve(TreeNode* root, int start){
        if(root==NULL) return 0;

        //get both left and right
        int LH=solve(root->left,start);
        int RH=solve(root->right,start);

        //special case when root is affected
        if(root->val==start) {
            longestPath=max(LH,RH);
            return -1;
        }
        else if(LH<0 or RH<0){
            //children is start node(infection)
            longestPath=max(longestPath, abs(LH)+abs(RH));
            return min(LH,RH)-1;
        }
        else{
            //child is not affected(start node is not the child)
            return max(LH,RH)+1;
        }

    }
public:
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return longestPath;
    }
};