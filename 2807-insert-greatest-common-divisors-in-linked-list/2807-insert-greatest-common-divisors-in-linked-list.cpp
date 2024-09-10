class Solution {
public:
    int gcd(int a, int b) {
        // Base case: when b becomes 0, a is the GCD
        if (b == 0)
            return a;

        // Recursive call: gcd of b and remainder of a divided by b
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            int a = prev->val;
            int b = curr->val;

            int g=gcd(a,b);

            ListNode *mid=new ListNode(g);
            prev->next=mid;
            mid->next=curr;

            prev=curr;
            curr=curr->next;
        }

        return head;
    }
};