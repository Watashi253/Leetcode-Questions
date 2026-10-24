class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n=target.size();
        unordered_set<int> hash;

        for(int i=0; i<n; i++){
            if(nums[i]!=target[i]){
                hash.insert(nums[i]);
            }
        }

        return (int)hash.size();
    }
};