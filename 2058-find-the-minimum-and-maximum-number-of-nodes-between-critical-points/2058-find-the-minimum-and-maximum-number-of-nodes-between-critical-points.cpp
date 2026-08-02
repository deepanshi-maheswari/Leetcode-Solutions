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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1}; //minDist, maxDist

        ListNode* prev = head;
        if(!prev) return ans;

        ListNode* curr = head->next;
        if(!curr) return ans;

        ListNode* temp = curr->next;
        if(!temp) return ans;

        int firstCp = -1;
        int lastCp = -1;
        int minDist = INT_MAX;
        int i = 1;
        while(temp){
            bool isCP = ((curr->val > prev->val && curr->val > temp->val) || (curr->val < prev->val && curr->val < temp->val)) ? true : false;

            if(isCP && firstCp == -1){
                firstCp = i;
                lastCp = i;
            }
            else if(isCP){
                minDist = min(minDist, i - lastCp);
                lastCp = i;
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            temp = temp->next;
        }

        if(lastCp == firstCp){
            //only one was found
            return ans;
        }
        else{
            ans[0] = minDist;
            ans[1] = lastCp - firstCp;
        }

        return ans;

    }
};