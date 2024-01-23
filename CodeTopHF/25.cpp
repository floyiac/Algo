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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        int count = 0;
        ListNode* cur = head;
        ListNode* prev = &dummy;
        ListNode* nex = nullptr;

        while(cur){
            cur = cur->next;
            count++;
        }

        cur = head;
        while(count >= k){
            cur = prev->next;
            nex = cur->next;
            for(int i=1;i<k;i++){
                // reverse three steps
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            count -= k;
        }
        return dummy.next;
    }
};