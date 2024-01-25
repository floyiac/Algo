class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1){
            return s;
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0;
        int max_length = 1;
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }

        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }

        for(int length =3; length <= n; length++){
            for(int i=0; i<=n-length;++i){
                int j = i+length-1;
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if(length > max_length){
                        start = i;
                        max_length = length;
                    }
                }
            }
        }
        return s.substr(start,max_length);
    }
};