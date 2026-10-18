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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end, unordered_map<int,int>& mp){
        if(start > end){
            return NULL;
        }

        int element = postorder[index--];

        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        root->right = solve(inorder, postorder, index, position + 1, end, mp);

        root->left = solve(inorder, postorder, index, start, position - 1, mp);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;

        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(inorder, postorder, index, 0, inorder.size() - 1, mp);
    }
};