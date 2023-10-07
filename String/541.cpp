class Solution {
public:
    string reverse(string& s, int left, int right){
        while(left < right){
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left ++;
            right --;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k){
            if(i+k-1<=s.size()-1){
                reverse(s,i,i+k-1);
            }
            else{
                reverse(s,i,s.size()-1);
            }
        }
        return s;
    }
};
