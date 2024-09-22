/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* convertArrToBST(vector<int> &nums,int l,int h){     
        if(l>h) return NULL;
        int mid=l+(h-l)/2;

        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=convertArrToBST(nums,l,mid-1);
        curr->right=convertArrToBST(nums,mid+1,h);

        return curr;

    }
    vector<int> convertLLtoArr(ListNode*& head) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        return nums;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums = convertLLtoArr(head);
        int n=nums.size();
        TreeNode* root=convertArrToBST(nums,0,n-1);

        return root;
    }
};