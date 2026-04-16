class Solution {
public:
vector<int> findnse(vector<int>& nums){
    stack<int> st;
    vector<int> nse(nums.size());
for(int i=nums.size()-1; i>=0;i--){
while(!st.empty() && nums[st.top()]>nums[i]){
    st.pop();
}
if(st.empty())
nse[i]=nums.size();
else{
   nse[i]=st.top(); 
}
st.push(i);
}
return nse;
}
vector<int> findpse(vector<int>& nums){
      stack<int> st;
    vector<int> pse(nums.size());
for(int i=0; i<nums.size();i++){
while(!st.empty() && nums[st.top()]>=nums[i]){
    st.pop();
}
if(st.empty())
pse[i]=-1;
else{
   pse[i]=st.top(); 
}
st.push(i);
}
return pse;  
}
long long subArrayMin(vector<int>& nums)  {
        vector<int> nse=findnse(nums);
        vector<int> pse=findpse(nums);
        long long ans=0;
        for(int i=0; i<nums.size();i++){
            ans+=(((nse[i]-i)*(i-pse[i])*1LL)*nums[i]);
        }
        return ans;
    }
vector<int> findnle(vector<int>& nums){
    stack<int> st;
    vector<int> nle(nums.size());
for(int i=nums.size()-1; i>=0;i--){
while(!st.empty() && nums[st.top()]<nums[i]){
    st.pop();
}
if(st.empty())
nle[i]=nums.size();
else{
   nle[i]=st.top(); 
}
st.push(i);
}
return nle;
}
vector<int> findple(vector<int>& nums){
      stack<int> st;
    vector<int> ple(nums.size());
for(int i=0; i<nums.size();i++){
while(!st.empty() && nums[st.top()]<=nums[i]){
    st.pop();
}
if(st.empty())
ple[i]=-1;
else{
   ple[i]=st.top(); 
}
st.push(i);
}
return ple;  
}
long long subArrayMax(vector<int>& nums)  {
        vector<int> nle=findnle(nums);
        vector<int> ple=findple(nums);
        long long ans=0;
        for(int i=0; i<nums.size();i++){
            ans+=(((nle[i]-i)*(i-ple[i])*1LL)*nums[i]);
        }
        return ans;
    }
long long subArrayRanges(vector<int>& nums){
    long long mx=subArrayMax(nums);
    long long mn=subArrayMin(nums);
return (mx-mn);
}
};
