class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,0,res,"");
        return res;
    }

    void generate(int n, int open, int close, vector<string>& res, string current){
        if(current.length() == 2 * n){
            res.push_back(current);
            return ;
        }
        if(open < n){
            generate(n,open+1,close,res,current + "(");
        }
        if(close < open){
            generate(n,open,close+1,res,current + ")");
        }
    }
};