class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }
            else{
                if(!stk.empty()){
                    if((s[i]==')' && stk.top() != '(') ||
                       (s[i]==']' && stk.top() != '[') ||
                       (s[i] == '}' && stk.top() != '{')
                    ){
                        return false;
                    }
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
