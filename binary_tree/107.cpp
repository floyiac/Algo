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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root != nullptr){q.push(root);}
        while(!q.empty()){
            int size = q.size();
            vector<int> store;
            for(int i=0; i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                store.push_back(temp->val);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            res.push_back(store);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
