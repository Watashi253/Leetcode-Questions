class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxind=0;

        for(int i=0; i<n-1; i++){
            maxind=max(i+nums[i], maxind);
            if(maxind<=i)return false;
        }

        return true;
    }
};