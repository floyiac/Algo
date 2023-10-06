class Solution {
public:
    int climbStairs(int n) {
        //dp[i] indicates there are x methods for step i
        if(n==1) return 1;
        if(n==2) return 2;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        int sum;
        for(int i=2;i<n;i++){
            sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};