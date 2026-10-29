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
    void getInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);

        TreeNode* dummy = new TreeNode(0);
        TreeNode* temp = dummy;

        for(int i: inorder){
            temp->right = new TreeNode(i);
            temp = temp->right;
        }

        return dummy->right;
    }
};