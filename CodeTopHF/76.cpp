class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int> tFreq;
        for(char c : t){
            tFreq[c]++;
        }

        unordered_map<char,int> window;
        int left = 0, right = 0;
        int match = 0;
        int need = tFreq.size();
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()){
            char c = s[right];
            if(tFreq.count(c)){
                window[c]++;
                if(window[c] == tFreq[c]){
                    match++;
                }
            }
            right++;
            while(match == need){
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }
                char leftChar = s[left];
                if(tFreq.count(leftChar)){
                    window[leftChar]--;
                    if(window[leftChar] < tFreq[leftChar]){
                        match--;
                    }
                }
                left++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start,minLen);
    }
};