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
    ListNode* removeElements(ListNode* head, int val) {
        //Delete head node if possible
        while(head != nullptr && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        //delete node that is not head node;
        ListNode* cur = head;
        while(cur!= nullptr && cur->next != nullptr){
            // the order of the && operation is important
            if(cur->next->val == val){
                //delete node
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }    
        return head;
    }
};
