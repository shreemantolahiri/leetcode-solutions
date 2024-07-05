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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nex=curr->next;
        int ctr=1;
        int last=0;
        int first=0;
        vector<int> res={INT_MAX,-1}; //min,max
        while(nex!=NULL){
            //maxima
            if(prev->val<curr->val && nex->val<curr->val){
                if(last!=0){
                    res[0]=min(res[0],ctr-last);
                    
                }
                last=ctr;
                if(first==0) first=ctr;

                cout<<ctr<<endl;
            }

            //minima
            else if(prev->val>curr->val && nex->val>curr->val){
                if(last!=0){
                    res[0]=min(res[0],ctr-last);
                    
                }
                last=ctr;
                if(first==0) first=ctr;

                 cout<<ctr<<endl;
            }

            prev=curr;
            curr=nex;
            nex=nex->next;
            ctr++;
        }
        if(last==0 || first==0 || first==last) return {-1,-1};
        cout<<last<<" "<<first<<endl;
        if(last!=0 && first!=0)res[1]=last-first;

        return res;
    }
};