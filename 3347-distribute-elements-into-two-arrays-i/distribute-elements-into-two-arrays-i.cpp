class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
       vector<int> arr1, arr2, result;
       int n=nums.size();
       arr1.push_back(nums[0]);
       arr2.push_back(nums[1]);
       for(int i=2; i<n; i++){
        if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
            arr1.push_back(nums[i]);
        }
        else{
            arr2.push_back(nums[i]);
        }
       }

       result = arr1;
       result.insert(result.end(), arr2.begin(), arr2.end());
       return result; 
    }
};