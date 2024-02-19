class Solution {
public:
    void trimSpace(string& s){
        int start = 0;
        int end = s.length() - 1;
        while(start <= end && s[start] == ' ') start ++;
        while(end >= start && s[end] == ' ') end--;
        s = s.substr(start,end-start+1);
    }
    string reverseWords(string s) {
        trimSpace(s);
        reverse(s.begin(),s.end());
        int start = 0;
        for(int i=0;i<=s.length();i++){
            if(i == s.length() || s[i] == ' '){
                reverse(s.begin()+start,s.begin() + i);
                start = i+1;
            }
        }
        string res;
        bool inWord = false;
        for(char c : s){
            if(c != ' '){
                if(!inWord && !res.empty()) res += ' ';
                inWord = true;
                res += c;
            }
            else{
                inWord = false;
            }
        }
        return res;
    }
};