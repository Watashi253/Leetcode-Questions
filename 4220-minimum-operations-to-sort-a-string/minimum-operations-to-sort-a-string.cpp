class Solution {
public:
    int minOperations(string s) {
        int n=s.size();

        if(is_sorted(s.begin(), s.end())) return 0;
        if(n==2) return -1;

        unordered_map<char, int> hash;

        int mn=0, mx=0;

        for(int i=0; i<n; i++){

            if(hash.contains(s[i])) hash[s[i]]++;
            else hash[s[i]]=1;

            if(s[i]<s[mn]) mn=i;
            if(s[i]>=s[mx]) mx=i;
        }

        if(mn==0 || mx==n-1) return 1;

        if((mn==n-1 && hash[s[mn]]==1) && (mx==0 && hash[s[mn]]==1)) return 3;

        return 2;

    }
};