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
    TreeNode* trav(TreeNode* root1, TreeNode* root2){
        int value = INT_MIN;
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        else if(root1 == NULL && root2 !=NULL){
            return root2;
        }
        else if(root1 != NULL && root2 == NULL){
            return root1;
        }
        else{
            value = root1->val + root2->val;        
            TreeNode* temp = new TreeNode(value);
            temp->left = trav(root1->left,root2->left);
            temp->right = trav(root1->right,root2->right);
            return temp;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return trav(root1,root2);
    }
};
