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
    struct compare{
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        for(ListNode* list : lists){
            if(list) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();

            cur->next = smallest;
            cur = cur->next;

            if(smallest->next){
                pq.push(smallest->next);
            }
        }
        return dummy.next;
    }
};