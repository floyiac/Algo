class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    void backtrack(string& s, int index){
        if(index >= s.size()){
            // end of backtrack
            res.push_back(path);
            return ;
        }
        for(int i=index; i<s.size();i++) {
            if (isPalindrome(s, index, i)) {
                //find a palindrome substring
                string temp = s.substr(index, i-index+1);
                path.push_back(temp);
            }
            else{
                continue;
            }
            backtrack(s,i+1);
            path.pop_back();
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start] == s[end]){
                start += 1;
                end -= 1;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        backtrack(s,0);
        return res;
    }
};