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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddleNode(ListNode* temp){
        if(temp->next==NULL) return temp;
        ListNode* fast=temp->next;
        ListNode* slow=temp;

        while(fast && fast->next){
            fast=fast->next;
            if(fast) fast=fast->next;

            if(slow) slow=slow->next;
        }

        return slow;
    }
    ListNode* getPrevNode(ListNode* head,ListNode* target){
        ListNode* prev=NULL;
        if(head==target) return prev;
        while(head && head!=target){
            prev=head;
            head=head->next;
        }

        return prev;
    }
    TreeNode* buildBST(ListNode* &head){
        if(head==NULL) return NULL;

        //root node=mid node
        ListNode* mid=getMiddleNode(head);
        if(mid==NULL) return NULL;
        cout<<mid->val<<endl;
        TreeNode* root=new TreeNode(mid->val);

        //break the LL
        ListNode* prev=getPrevNode(head,mid);
        if(prev) prev->next=NULL;

        //leftChild
        if(!prev) root->left=NULL;
        else root->left=buildBST(head);
        //rightChild
        root->right=buildBST(mid->next);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head);
    }
};