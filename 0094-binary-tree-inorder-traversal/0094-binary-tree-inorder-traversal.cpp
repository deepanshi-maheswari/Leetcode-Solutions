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
    vector<int> ans;

    void inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }

        inorder(root -> left);  //left subtree
        ans.push_back(root -> val);  //root value
        inorder(root -> right);   //right subtree
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);

        return ans;
    }
};