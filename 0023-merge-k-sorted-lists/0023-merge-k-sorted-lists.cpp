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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>> >pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) continue;
            pq.push({lists[i]->val,lists[i]});
        }

        ListNode* dummyHead=new ListNode(-1);
        ListNode* curr=dummyHead;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ListNode* temp=it.second;
            if(temp->next!=NULL) 
            pq.push({temp->next->val,temp->next});
            
            curr->next=temp;
            curr=curr->next;
            curr->next=NULL;
        }

        return dummyHead->next;
    }
};