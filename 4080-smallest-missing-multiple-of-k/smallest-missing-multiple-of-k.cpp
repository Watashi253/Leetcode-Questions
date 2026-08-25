class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size(), i=1;
        unordered_set<int> c(nums.begin(), nums.end());

        while(i<=n){
            if(!c.count(k*i)){
                return k*i;
            }
            i++;
        }

        return k*i;
    }
};