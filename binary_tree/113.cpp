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
    void trav(TreeNode* s, int targetSum, vector<vector<int>>&res, vector<int> store){
        targetSum -= s->val;
        store.push_back(s->val);
        if(targetSum == 0 && s->left == NULL && s->right == NULL){
            //Node must be leaf and targetSum must be zero
            res.push_back(store);
        }
        if(s->left !=NULL){
            trav(s->left,targetSum,res,store);
        }
        if(s->right !=NULL){
            trav(s->right,targetSum,res,store);
        }
        // Backtracking!
        store.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root == NULL){return res;}
        vector<int> store;
        trav(root,targetSum,res,store);
        return res;
    }
};
