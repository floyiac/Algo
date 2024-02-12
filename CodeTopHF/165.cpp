class Solution {
public:
    vector<int> split(const string& s){
        int start = 0;
        vector<int> res;
        for(int i=0;i<=s.length();i++){
            // should be i <= to ensure that the last digit is considered
            if(i == s.length() || s[i] == '.'){
                res.push_back(stoi(s.substr(start,i-start)));
                start = i + 1;
            }
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int> a = split(version1);
        vector<int> b = split(version2);
        int n1 = a.size();
        int n2 = b.size();
        for(int i=0;i<max(n1,n2);i++){
            int v1 = (i<n1)? a[i] : 0;
            int v2 = (i<n2)? b[i] : 0;
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        return 0;
    }
};