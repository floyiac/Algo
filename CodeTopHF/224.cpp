class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops; // two stacks: nums for number and ops for signs
        int currentNumber = 0;
        int sign = 1;
        int result = 0;

        for(char c : s){
            if(isdigit(c)){
                currentNumber = currentNumber * 10 + (c - '0');
            }
            else if(c == '+' || c == '-'){
                result += sign * currentNumber;
                currentNumber = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if(c == '('){
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')'){
                result += sign * currentNumber;
                currentNumber = 0;
                result *= ops.top(); ops.pop();
                result += nums.top(); nums.pop();
            }
        }
        result += sign * currentNumber;
        return result;
    }
};