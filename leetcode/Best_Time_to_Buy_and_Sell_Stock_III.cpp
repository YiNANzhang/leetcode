class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        pair<int, int> profits[n];
        fill(profits, profits+n, make_pair(0, 0));
        int min_val[n];
        fill(min_val, min_val+n, prices[0]);
        for(int i=1;i<n;i++){
            profits[i].first = prices[i]-min_val[i-1]>profits[i-1].first?prices[i]-min_val[i-1]:profits[i-1].first;
            min_val[i] = prices[i]<min_val[i-1]?prices[i]:min_val[i-1];
        }
        int max_val[n];
        fill(max_val, max_val+n, prices[n-1]);
        for(int i=n-2;i>=0;i--){
            profits[i].second = max_val[i+1]-prices[i]>profits[i+1].second?max_val[i+1]-prices[i]:profits[i+1].second;
            max_val[i] = prices[i]>max_val[i+1]?prices[i]:max_val[i+1];
        }
        
        int max_profit = 0;
        for(int i=0;i<n;i++){
            max_profit = max(max_profit, profits[i].first + profits[i].second);
        }
        return max_profit;
    }
};
