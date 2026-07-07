class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), c(n,1);
        int maxi=1, ci=0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    c[i]=c[j];
                }
                else if(dp[i]==1+dp[j]){
                    c[i]+=c[j];
                }    
                }
            }
            maxi=max(dp[i], maxi);
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ci += c[i];
            }
        }
        return ci;
    }
};