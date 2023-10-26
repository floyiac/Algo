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
    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0){
            return NULL;
        }
        int root_value = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(root_value);

        if(postorder.size() == 1){
            return root;
        }
        for(int i=0; i<inorder.size() ; i++){
            if(inorder[i] == root_value){
                break;
            }
        }
        int div = 0;
        for(;div<inorder.size();div++){
            if(inorder[div] == root_value){
                break;
            }
        }

        vector<int> left_inorder(inorder.begin(),inorder.begin()+div);
        vector<int> right_inorder(inorder.begin()+div + 1,inorder.end());

        postorder.resize(postorder.size()-1);

        vector<int> left_postorder(postorder.begin(),postorder.begin()+left_inorder.size());
        vector<int> right_postorder(postorder.begin()+left_inorder.size(),postorder.end());
        root->left = traverse(left_inorder,left_postorder);
        root->right = traverse(right_inorder,right_postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }   
        return traverse(inorder,postorder);
    }
};
