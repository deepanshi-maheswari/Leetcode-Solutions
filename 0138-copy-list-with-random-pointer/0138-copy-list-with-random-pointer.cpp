/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Node* helperold(Node* head, unordered_map<Node*, Node*>& mp){
    //     if(head == NULL) return 0;

    //     Node* newHead = new Node(head->val);
    //     mp[head] = newHead;
    //     newHead->next = helper(head->next, mp);

    //     if(head->random){
    //         newHead->random = mp[head->random];
    //     }
    //     return newHead;
    // }

    
    Node* copyRandomList(Node* head) {
        // unordered_map<Node* , Node*> mp; //old node -> new node
        // return helper(head, mp);

        if(!head) return 0;

        //Step 1: Clone A - A'
        Node* it = head; //iterate over old head
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        //Step 2: Assign random links of A' with help of A
        it = head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : NULL;
            it = it->next->next;
        }

        //Step 3: Detech A' from A
        it = head;
        Node* cloneHead = it->next;
        while(it){
            Node* temp = it->next;
            it->next = it->next->next;
            if(temp->next){
                temp->next = temp->next->next;
            }
            it = it->next;
        }

        return cloneHead;
    }
};