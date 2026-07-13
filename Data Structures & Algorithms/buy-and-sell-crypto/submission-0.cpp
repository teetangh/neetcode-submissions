class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minUntilNow = prices[0];
        for(int i = 1; i < prices.size() ; i++){
            int profit = prices[i] - minUntilNow;
            maxProfit = max(maxProfit,profit);
            if (prices[i] < minUntilNow)
                minUntilNow = prices[i];
        }

        return maxProfit;
    }
};
