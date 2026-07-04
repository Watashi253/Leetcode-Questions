class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), minprice=1e9, maxprofit=-1e9;

        for(int i=0; i<n ; i++){
            minprice=min(minprice, prices[i]);
            maxprofit=max(maxprofit, prices[i]-minprice);
        }
        return maxprofit;
    }
};