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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;

        bool leftToright = true;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            deque<int> level;

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(leftToright){
                    level.push_back(node->val);
                }
                else{
                    level.push_front(node->val);
                }

                if(node->left !=  nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            res.push_back(vector<int>(level.begin(), level.end()));
            leftToright = !leftToright;
        }

        return res;
    }
};