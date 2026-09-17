class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]);

            int todayProfit = prices[i] - minPrice;
            
            maxProfit = max(maxProfit, todayProfit);
        }

        return maxProfit;
    }
};