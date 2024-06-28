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
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* prev=NULL;
        ListNode* start=head;
        ListNode* end=head;
        ListNode* newHead=NULL;
        
        while(end!=NULL){
        end=start;
        int len=1;
        for(int i=0;i<k-1;i++){
            if(end==NULL || end->next==NULL) break;
            len++;
            end=end->next;
        }
        if(len<k){
            //not enough nodes
            if(prev!=NULL) prev->next=start;
            break;
        }
        ListNode* nexStart=end->next;
        end->next=NULL;
        ListNode* temp=reverseLL(start);
        if(newHead==NULL) newHead=temp;

        if(prev!=NULL) prev->next=temp;
        prev=start;
        start=nexStart;
        }
        
        return newHead;
    }
};