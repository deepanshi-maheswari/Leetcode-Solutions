/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    //Serialize
    void serializeHelper(TreeNode* root, string& s){
        if(root == NULL){
            s += "N,";
            return;
        }

        s += to_string(root -> val) + ",";

        serializeHelper(root -> left , s);
        serializeHelper(root -> right , s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root , s);
        return s;
    }

    //Desearialize
    TreeNode* deserializeHelper(queue<string>& q){

        string val = q.front();
        q.pop();

        if(val == "N")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));

        root -> left = deserializeHelper(q);
        root -> right = deserializeHelper(q);

        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;

        string temp = "";

        for(char ch:data){
            if(ch == ','){
                q.push(temp);
                temp = "";
            }
            else{
                temp += ch;
            }
        }

        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));