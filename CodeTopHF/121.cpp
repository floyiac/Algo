class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //greedy approach
        int low = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            low = min(low,prices[i]);
            profit = max(profit,prices[i] - low);
        }
        return profit;
    }
};