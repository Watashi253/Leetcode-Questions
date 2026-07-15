class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet( int n ){
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
    }
    int find(int node){
        if(par[node]==node){
            return node;
        }
        return par[node]=find(par[node]);
    }
    void unionbySize(int u, int v){
        int rootU=find(u);
        int rootV=find(v);
        if(rootU==rootV)return;

        if (size[rootU] < size[rootV]) {
            par[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            par[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> emails;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email=accounts[i][j];
                if(emails.count(email)){
                    ds.unionbySize(emails[email], i);
                }
                else{
                    emails[email]=i;
                }
            }
        }

        unordered_map<int, vector<string>> mergedEmails;
        for(auto & acc: emails){
            string email=acc.first;
            int i=acc.second;

            int root=ds.find(i);
            mergedEmails[root].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto& acc: mergedEmails){
            int i=acc.first;
            vector<string>email=acc.second;
            sort(email.begin(), email.end());

            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[i][0]);
            mergedAccount.insert(mergedAccount.end(), email.begin(), email.end());
            ans.push_back(mergedAccount);
        }

        return ans;
    }
};