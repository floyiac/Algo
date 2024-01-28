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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root == NULL){
            return res;
        }
        que.push(root);
        int count = 0;
        while(!que.empty()){
            int size =  que.size();
            vector<int> curAns(size);
            for(int i=0;i<size;i++){
                TreeNode* front = que.front();
                que.pop();
                if(count % 2 == 1){
                    curAns[size-i-1] = front->val;
                }
                else{
                    curAns[i] = front->val;
                }
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            res.push_back(curAns);
            count++;
        }
        return res;
    }
};