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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            count++;
        }

        if(n == count){
            // special case head deletion
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        cur = head;
        for(int i=0;i<count-n-1;i++){
            cur = cur->next;
        }

        ListNode* target = cur->next;
        cur->next = target->next;
        delete target;
        return head;
    }
};


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode dummy(0,head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummy.next;
    }
};