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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> s;
        vector<int> ans(ll.size());

        for(int i = 0; i < ll.size(); i++){
            while(!s.empty() && ll[s.top()] < ll[i]){
                //means, ith element is the next greater of the elementindex present in stack
                int kids = s.top();
                s.pop();
                ans[kids] = ll[i];
            }

            s.push(i);
        }

        return ans;
    }
};