/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(root != nullptr){q.push(root);}
        while(!q.empty()){
            int size = q.size();
            vector<int> store;
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                store.push_back(temp->val);
                for(int i=0;i<temp->children.size();i++){
                    if(temp->children[i]){q.push(temp->children[i]);}
                }
            }
            res.push_back(store);
        }
        return res;
    }
};
