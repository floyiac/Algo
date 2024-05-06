class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> res(numRows);
        int i=0; int flag = -1;
        for(char c : s){
            res[i]  += c;
            if(i == 0 || i == numRows - 1){
                flag = -flag;
            }
            i += flag;
        }
        string ans;
        for(const string c : res){
            ans += c;
        }
        return ans;
    }
};