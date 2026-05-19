class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l=0, r=0,c=0;
        int ans=INT_MAX;
while(l<nums1.size() && r<nums2.size()){
    if(nums1[l]<nums2[r])l++;
    else if(nums1[l]==nums2[r]){
        c++;
        ans=min(ans,nums1[l]);
        l++, r++;
    }
    else r++;
}
if(c==0) return -1;
return ans;
    }
};