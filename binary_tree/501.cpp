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
private:
    int count = 0;
    int maxcount = 0;
    vector<int> res;
    TreeNode* pre = NULL;
    void trav(TreeNode* cur){
        //end recursion if null
        if(cur == NULL){return ;}
        //inorder trav
        trav(cur->left);
        if(pre == NULL){
            count = 1;
        }
        else if(pre->val == cur->val){
            count ++;
        }
        else{
            count = 1;
        }
        if(count == maxcount){
            res.push_back(cur->val);
        }
        // move pre to cur
        pre = cur;
        if(count > maxcount){
            maxcount = count;
            res.clear(); //not the most frequently occured. clear vector
            res.push_back(cur->val);
        }
        trav(cur->right); //right
        return ;
    }
public:
    vector<int> findMode(TreeNode* root) {
        trav(root);
        return res;
    }
};
