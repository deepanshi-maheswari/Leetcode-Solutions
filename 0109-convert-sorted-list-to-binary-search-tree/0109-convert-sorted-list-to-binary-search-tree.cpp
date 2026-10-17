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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertIntoBST(ListNode* &head, int n){
        if(head == NULL || n <= 0){
            return NULL;
        }

        TreeNode* leftSubtree = convertIntoBST(head,  n /2);

        TreeNode* temp = new TreeNode(head->val);
        temp->left = leftSubtree;
        head = head->next;
        temp->right = convertIntoBST(head, n - 1 - n / 2);

        return temp;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* root = head;

        while(root != NULL){
            n++;
            root = root->next;
        }

        return convertIntoBST(head, n);
    }
};