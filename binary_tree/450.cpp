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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            //didn't find the node to be deleted.
            return root;
        }
        if(root->val == key){
            // leaf
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // case 2
            if(root->left != nullptr && root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //case 3
            if(root->left == nullptr && root->right != nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //case 4
            if(root->left != nullptr && root->right != nullptr){
                TreeNode* cur = root->right;
                while(cur->left != NULL){
                    cur = cur->left;
                }
                // append root->left to cur
                cur->left = root->left;
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
        }
        if(root->val > key){root->left = deleteNode(root->left,key);}
        if(root->val < key){root->right = deleteNode(root->right,key);}
        return root;
    }
};
