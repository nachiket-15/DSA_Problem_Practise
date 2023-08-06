class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyAtPrice = prices[0];
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            buyAtPrice = min(buyAtPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
        }
        return maxProfit;
    }
};