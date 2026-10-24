class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int k=-1, maxk=-1, len=0;
        for(int i=0; i<n; i++){
            maxk=max(maxk, nums[i]);
        }

        for(int i=0; i<n; i++){
            int c=0;
            while(i<n && nums[i]==maxk){
                c++;
                len=max(len,c);
                i++;
            }
        }

        return len;
    }
};