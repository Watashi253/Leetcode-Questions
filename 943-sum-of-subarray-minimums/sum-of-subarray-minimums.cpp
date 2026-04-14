class Solution {
public:
vector<int> findnse(vector<int>& arr){
    stack<int> st;
    vector<int> nse(arr.size());
for(int i=arr.size()-1; i>=0;i--){
while(!st.empty() && arr[st.top()]>arr[i]){
    st.pop();
}
if(st.empty())
nse[i]=arr.size();
else{
   nse[i]=st.top(); 
}
st.push(i);
}
return nse;
}
vector<int> findpse(vector<int>& arr){
      stack<int> st;
    vector<int> pse(arr.size());
for(int i=0; i<arr.size();i++){
while(!st.empty() && arr[st.top()]>=arr[i]){
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        int ans=0;
        int mod=(int)1e9+7;
        for(int i=0; i<arr.size();i++){
            ans+=(((nse[i]-i)*(i-pse[i])*1LL)%mod*arr[i])%mod;
            ans%=mod;
        }
        return ans;
    }
};