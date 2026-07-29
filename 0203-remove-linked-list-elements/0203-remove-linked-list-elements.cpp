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
        
        // ListNode dummy(0);
        // dummy.next = head;

        // ListNode* prev = &dummy;
        // ListNode* curr = head;

        // while (curr != NULL) {

        //     if (curr->val == val) {
        //         prev->next = curr->next;
        //         ListNode* temp = curr;
        //         curr = curr->next;
        //         delete temp;
        //     }
        //     else {
        //         prev = curr;
        //         curr = curr->next;
        //     }
        // }

        // return dummy.next;

        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        if(head == NULL)
            return NULL;


        //if multiple same val present then:
        ListNode* curr = head;
        
        while(curr->next != NULL){
            if(curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                //temp->next = NULL;
                delete temp; 
            }
            else{
                curr = curr->next;
            }
        }


        return head;
    }
};