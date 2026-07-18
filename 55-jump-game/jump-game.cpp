class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxind=0;

        for(int i=0; i<n; i++){
            int ind=i+nums[i];
            if(i>maxind) return false;
            else if(ind>maxind){
                maxind=i+nums[i];
            }

            if(maxind>=n-1) return true;
        }
        
        return false;
    }
};