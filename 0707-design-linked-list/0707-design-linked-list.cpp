class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;

        Node(int x){
            val = x;
            next = NULL;
        }
    };
    
    Node* head;

    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* curr = head;

        int idx = 0;
        while(curr != NULL){
            if(idx == index){
                return curr->val;
            }

            idx++;
            curr = curr->next;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            return;
        }

        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next; //finding tail node
        }
        curr->next = temp;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0){
            return; //index is not find
        }
        if(index == 0){
            addAtHead(val);
            return;
        }

        Node* curr = head;
        int idx = 0;

        while(curr != NULL && idx < index - 1){
            curr = curr->next;
            idx++;
        }

        if(curr == NULL) return;

        Node* temp = new Node(val);
        temp->next = curr->next;
        curr->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0) return;

        if(index == 0){
            Node* temp = head;
            head = head->next;
            //temp->next = NULL;
            delete temp;
            return;
        }

        Node* curr = head;
        int idx = 0;
        while(curr->next != NULL && idx < index - 1){
            curr = curr->next;
            idx++;
        }

        if(curr == NULL || curr->next == NULL) return;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
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