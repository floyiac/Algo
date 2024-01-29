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
        ListNode* trav_A = headA;
        ListNode* trav_B = headB;
        while(trav_A){
            trav_A = trav_A->next;
            lenA++;
        }

        while(trav_B){
            trav_B = trav_B->next;
            lenB++;
        }

        while(lenA>lenB){
            headA = headA->next;
            lenA--;
        }

        while(lenB>lenA){
            headB = headB->next;
            lenB--;
        }

        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }

        return NULL;

    }
};