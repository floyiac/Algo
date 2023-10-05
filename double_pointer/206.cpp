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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummy = nullptr;
        while(cur!=nullptr){
            ListNode* temp;
            temp = cur->next;
            cur->next = dummy;
            dummy = cur;
            cur = temp;
        }
        return dummy;
    }
};
