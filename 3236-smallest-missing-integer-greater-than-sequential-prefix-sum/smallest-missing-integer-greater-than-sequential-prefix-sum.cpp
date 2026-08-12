class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]+1){
                break;
            }
                sum+=nums[i];
        }

        int ans=sum;
        unordered_set <int> help(nums.begin(), nums.end());
            while(help.count(ans)){
                ans++;
            }

            return ans;
    }
};