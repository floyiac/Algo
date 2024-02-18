class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        int maxLength = 0;
        indices.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                indices.push(i);
            }
            else{
                indices.pop();
                if(indices.empty()){
                    indices.push(i);
                }
                else{
                    maxLength = max(maxLength,i-indices.top());
                }
            }
        }
        return maxLength;
    }
};
