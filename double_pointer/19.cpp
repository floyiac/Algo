class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head,int n ){
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* slow = dummyhead;
        ListNode* fast = dummyhead;
        for(int i=0;i<n+1;i++){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast =fast->next;
            slow =slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyhead->next;
    }
};