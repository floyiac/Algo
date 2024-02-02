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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            res.push_back(que.back()->val);
            int n = que.size();
            for(int i=0;i<n;i++){
                TreeNode* cur = que.front();
                if(cur->left){
                    que.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                }
                que.pop();
            }
        }
        return res;
    }
};