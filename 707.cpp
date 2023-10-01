class MyLinkedList {
public:
    struct Node{
        int val;
        Node* next;
        Node(int val): val(val),next(nullptr){}
    };

    MyLinkedList() {
        _dummyhead = new Node(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > (_size - 1)){
            return -1;
        }
        Node* cur = _dummyhead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = _dummyhead->next;
        _dummyhead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* cur = _dummyhead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return ;
        }
        if(index <0){
            index = 0;
        }
        Node* cur = _dummyhead;
        while(index--){
            cur = cur->next;
        }
        Node* newNode = new Node(val);
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index <0){
            return ;
        }
        if(index >= _size ){
            return ;
        }
        Node* cur = _dummyhead;
        while(index--){
            cur = cur->next;
        }
        Node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size--;
    }
private:
    int _size;
    Node* _dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
