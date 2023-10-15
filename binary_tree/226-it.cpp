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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> store;
        if(root == nullptr){return root;}
        store.push(root);
        while(!store.empty()){
            TreeNode* temp = store.top();
            store.pop();
            if(temp!=nullptr){
                swap(temp->left,temp->right);
                store.push(temp->right);
                store.push(temp->left);
            }
        }
        return root;
    }
};
