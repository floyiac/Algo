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
    vector<vector<int>> res;
    void trav(TreeNode* root, int targetSum, vector<int> path){
        int v = root->val;
        targetSum -= v;
        path.push_back(v);
        if(targetSum == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(path);
            return ;
        }
        if(root->left){
            trav(root->left,targetSum,path);
        }
        if(root->right){
            trav(root->right,targetSum,path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return res;
        vector<int> path;
        trav(root,targetSum,path);
        return res;
    }
};