class Solution {
public:
    int fib(int n) {
        //dp[i] means fib(int i)
        if(n==0) return 0;
        if(n==1) return 1;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        int sum;
        for(int i=1; i<n; i++){
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};