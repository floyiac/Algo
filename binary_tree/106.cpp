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
    TreeNode* traverse(vector<int>& in, vector<int>&post){
        if(post.size() == 0){
            return NULL;
        }
        int rootvalue = post[post.size()-1];
        TreeNode* root = new TreeNode(rootvalue);

        if(post.size() == 1){
            //Leaf Node
            return root;
        }

        //Seperate the in order
        int div = 0;
        for(;div<in.size();div++){
            if(in[div] == rootvalue){
                break;
            }
        }
        
        //Seperate in vector
        vector<int> in_left(in.begin(),in.begin()+div);
        vector<int> in_right(in.begin()+div+1,in.end());
        
        //Resize postorder to delete root
        post.resize(post.size()-1);
        
        vector<int> post_left(post.begin(),post.begin()+in_left.size());
        vector<int> post_right(post.begin()+in_left.size(),post.end());

        root->left =traverse(in_left,post_left);
        root->right = traverse(in_right,post_right);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return NULL;
        }
        return traverse(inorder,postorder);
    }
};
