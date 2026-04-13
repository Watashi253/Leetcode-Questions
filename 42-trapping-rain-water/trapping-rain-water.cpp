class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n=height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefixMax[0]=height[0];
        suffixMax[n-1]=height[n-1];
        for(int i=1; i<n; i++){
            prefixMax[i]=max(prefixMax[i-1], height[i]);
        }
                for(int i=n-2; i>=0; i--){
            suffixMax[i]=max(height[i], suffixMax[i+1]);
        }
        for (int i = 0; i < height.size(); i++) {

            if (height[i] < prefixMax[i] && height[i] < suffixMax[i]) {
                int mn = min(prefixMax[i], suffixMax[i]);
                ans += mn - height[i];
            }
        }
        return ans;
    }
};