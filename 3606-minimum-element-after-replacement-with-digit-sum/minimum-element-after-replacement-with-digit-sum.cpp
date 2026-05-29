class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int sum=0;
            int num=nums[i];
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            ans=min(sum, ans);          
        }
        return ans;
    }
};