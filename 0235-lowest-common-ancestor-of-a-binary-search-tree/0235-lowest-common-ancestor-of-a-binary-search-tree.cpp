/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //when root exist
        while(root){
            if(p -> val < root -> val && q -> val < root -> val){
                root = root -> left;  //left subtree point
            }
            else if(p -> val > root -> val && q -> val > root -> val){
                root = root -> right;  //right subtree point
            }  
            else{
                return root; //split point
            }
        }

        return nullptr;
    }
};