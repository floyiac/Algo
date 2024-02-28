class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> results;
        string res;
        int idx = 0;
        while(idx < s.size()){
            if(isdigit(s[idx])){
                int count = 0;
                while(isdigit(s[idx])){
                    count = 10 * count + (s[idx] - '0');
                    idx++;
                }
                counts.push(count);
            }
            else if(s[idx] == '['){
                results.push(res);
                res = "";
                idx++;
            }
            else if(s[idx] == ']'){
                int times = counts.top();
                counts.pop();
                string temp = res;
                res = results.top();
                results.pop();
                for(int i=0;i<times;i++){
                    res += temp;
                }
                idx++;
            }
            else{
                res += s[idx++];
            }
        }
        return res;
    }
};