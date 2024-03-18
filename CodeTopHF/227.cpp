class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char lastSign = '+';
        int num = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1){
                if(lastSign == '+'){
                    stk.push(num);
                }
                else if(lastSign == '-'){
                    stk.push(-num);
                }
                else if(lastSign == '*'){
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                }
                else if(lastSign == '/'){
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }
                num = 0;
                lastSign = s[i];
            }
        }
        int res = 0;
        while(!stk.empty()){
            int top = stk.top();
            res += top;
            stk.pop();
        }
        return res;
    }
};