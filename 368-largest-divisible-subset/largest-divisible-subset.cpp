class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=1;
        int last=0;

        for(int i=1; i<n; i++){
            hash[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1 + dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);

        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};