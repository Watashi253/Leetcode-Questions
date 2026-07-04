class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0, sell=0, cool=0;

        for(int i=n-1; i>=0; i--){
            int hold=buy;
            buy=max(-prices[i]+sell, buy);
            sell=max(+prices[i]+cool, sell);
            cool=hold;
        }
        return buy;
    }
};