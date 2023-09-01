class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least_price = INT_MAX;
        int max_profit = 0;
        int profit_now= 0;
        for(int i =0; i < prices.size(); i++){
            if(prices[i] < least_price){
                least_price = prices[i];
            }
            profit_now = prices[i] - least_price;
            if(max_profit < profit_now)
                max_profit = profit_now;
        }
    return max_profit;
    }
    
};