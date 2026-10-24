class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxk=-1, len=0;
        for(int i=0; i<n; i++){
            maxk=max(maxk, nums[i]);
        }

        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maxk){
                c++;
            }
            else{
                len=max(len, c);
                c=0;
            }
        }

        return max(len,c);
    }
};