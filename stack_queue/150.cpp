class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Use a stack to do calculation
        stack<long long> stk;
        for(int i=0; i< tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long b = stk.top();
                stk.pop();
                long long a = stk.top();
                stk.pop();
                if(tokens[i] == "+"){stk.push(a+b);}
                if(tokens[i] == "-"){stk.push(a-b);}
                if(tokens[i] == "*"){stk.push(a*b);}
                if(tokens[i] == "/"){stk.push(a/b);}
            }
            else{
                stk.push(stoll(tokens[i]));
            }
        }
        int res = stk.top();
        stk.pop();
        return res;
    }
};
