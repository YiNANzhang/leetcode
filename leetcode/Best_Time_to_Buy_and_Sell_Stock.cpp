class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0 || prices.size() ==1 ) return 0;
        int profit = 0;
        int min_price = prices[0];
        for(int i=1;i<prices.size();i++){
            profit = prices[i]-min_price>profit?prices[i]-min_price:profit;
            min_price = prices[i]-min_price<0?prices[i]:min_price;
        }
        return profit;
    }
};
