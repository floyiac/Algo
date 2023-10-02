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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA){
            curA = curA->next;
            lenA++;
        }
        while(curB){
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        while(lenA>lenB){
            curA = curA->next;
            lenA--;
        }
        while(lenA<lenB){
            curB = curB->next;
            lenB--;
        }
        while(curA){
            if(curA == curB){
                return curA;
            }
            else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return NULL;
    }
};
