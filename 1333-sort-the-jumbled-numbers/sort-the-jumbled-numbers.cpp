class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> mapped(n);

        for(int i=0; i<n; i++){
            
            int num=nums[i];
            mapped[i].second=i;

            if (num == 0) {
                mapped[i].first = mapping[0];
                continue;
            }

            int c=0;
            while(num!=0){
                mapped[i].first=mapping[num%10]*pow(10,c)+mapped[i].first;
                num=num/10;
                c++;
            }
        }

        sort(mapped.begin(), mapped.end());
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            ans[i]=nums[mapped[i].second];
        }

        return ans;
    }
};