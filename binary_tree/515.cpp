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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root != nullptr){
            q.push(root);
        }
        while(!q.empty()){
            int size = q.size();
            int comp = q.front()->val;
            for(int i=0; i<size;i++){
                TreeNode* temp =q.front();
                q.pop();
                comp = comp < temp->val? temp->val : comp;
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            res.push_back(comp);
        }
        return res;
    }
};
