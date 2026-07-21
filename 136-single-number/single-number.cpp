class Solution {
public:
const int N= 3 * 1e4;
    int singleNumber(vector<int>& nums) {
        vector<int> hash(2*N+1, 0);

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]+N]++;;
        }

        for(int i=0; i<2*N+1; i++){
            if(hash[i]==1) return i-N;
        }

        return -1;
    }
};