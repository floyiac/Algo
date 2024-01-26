class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            char cur = s[i];
            if(cur == '(' || cur == '[' || cur == '{'){
                stk.push(cur);
            }
            else if(!stk.empty()){
                if ((s[i] == ')' && stk.top() != '(') ||
                    (s[i] == ']' && stk.top() != '[') ||
                    (s[i] == '}' && stk.top() != '{')) {
                    return false;
                }
                stk.pop();
            }
            else{
                // closing bracket with empty stack
                return false;
            }
        }
        return stk.empty();
    }
};