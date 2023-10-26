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
    TreeNode* traverse(vector<int>&nums){
        if(nums.size() == 0){
            return NULL;
        }
        //find max value in nums
        int comp = INT_MIN;
        int j = 0; //max index
        for(int i=0; i<nums.size();i++){
            if(nums[i]>=comp){
                comp = nums[i];
                j = i;
            }

        }
        //Create return node;
        TreeNode* res = new TreeNode(comp);

        //divide vector;
        vector<int>left(nums.begin(),nums.begin()+j);
        vector<int>right(nums.begin()+j+1,nums.end());
        
        //recursion
        res->left = traverse(left);
        res->right = traverse(right);

        return res;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        return traverse(nums);
    }
};
