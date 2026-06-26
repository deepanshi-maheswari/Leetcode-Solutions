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
    bool isMirror(TreeNode* left , TreeNode* right){
        //both are empty
        if(left == nullptr && right == nullptr)
            return true;
        
        //one is empty
        if(left == nullptr || right == nullptr)
            return false;

        //one differ
        if(left -> val != right -> val)
            return false;
            

        return isMirror(left -> left , right -> right) && isMirror(left -> right , right -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        return isMirror(root -> left , root -> right);
    }
};