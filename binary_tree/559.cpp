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
    int maxDepth(Node* root) {
        int count = 0;
        queue<Node*> q;
        if(!root){
            return 0;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size;i++){
                Node* temp = q.front();
                q.pop();
                for(int k=0; k<temp->children.size();k++){
                    if(temp->children[k]){
                        q.push(temp->children[k]);
                    }
                }
            }
            count++;
        }
        return count;
    }
};
