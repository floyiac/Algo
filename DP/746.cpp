class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2];
        dp[0] = 0;
        dp[1] = 0;
        int sum;
        for(int i=1;i<cost.size();i++){
            sum = min(dp[0]+cost[i-1],dp[1]+cost[i]);
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};