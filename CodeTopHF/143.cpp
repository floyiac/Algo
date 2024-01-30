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
    void reorderList(ListNode* head) {
        // Use Deque to simulate
        deque<ListNode*> que;
        ListNode* cur = head;
        if(cur == nullptr) return ;
        while(cur->next){
            que.push_back(cur->next);
            cur = cur->next;
        }
        int count = 0;
        cur = head;
        ListNode* temp;
        while(!que.empty()){
            if(count % 2 == 1){
                temp = que.front();
                que.pop_front();
            }
            else{
                temp = que.back();
                que.pop_back();
            }
            count++;
            cur->next = temp;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};