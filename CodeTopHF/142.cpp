/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                ListNode* a = fast;
                ListNode* b = head;
                while(a != b){
                    a = a->next;
                    b = b->next;
                }
                return a;
            }
        }
        return NULL;
    }
};