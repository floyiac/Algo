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

    void helper(TreeNode* root, string& str){
        if(root == nullptr){
            str += "None,";
            return ;
        }
        str += to_string(root->val) + ",";
        helper(root->left,str);
        helper(root->right,str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        helper(root,str);
        return str;
    }

    TreeNode* de_helper(list<string>& dataArray){
        if(dataArray.front() == "None"){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = de_helper(dataArray);
        root->right = de_helper(dataArray);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for(auto& ch : data){
            if(ch == ','){
                dataArray.push_back(str);
                str.clear();
            }
            else{
                str.push_back(ch);
            }
        }
        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        return de_helper(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));