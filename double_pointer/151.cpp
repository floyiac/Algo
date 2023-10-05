class Solution {
public:
    void ReverseString(string& s, int start, int end){
        for(int i=start, j=end; i<=j; i++,j--){
            swap(s[i],s[j]);
        }
    }
    void RemoveSpace(string& s){
        int slow = 0;
        for(int i=0; i<s.size();i++){
            if(s[i] != ' '){
                if(slow !=0){
                    s[slow++] = ' ';
                }
                while(i<s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        RemoveSpace(s);
        ReverseString(s,0,s.size()-1);
        int start = 0;
        for(int j=0; j<=s.size();j++){
            if(s[j] == ' ' || j==s.size()){
                ReverseString(s,start,j-1);
                start = j+1;
            }
        }
        return s;
    }
};
