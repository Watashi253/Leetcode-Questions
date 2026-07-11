class DisjointSet {
public:
vector<int> par;
    DisjointSet(int n) {
        par.resize(n);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
    }

    int find(int node){
        if(par[node]==node)
        return node;
        else 
        return par[node]= find(par[node]);
    }

    void unionSet(int u, int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU!=rootV){
            par[rootU]=rootV;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet ds(n);
        
        int extract=0;
        for(auto c: connections){
            if(ds.find(c[0])==ds.find(c[1])) extract++;
            else
            ds.unionSet(c[1], c[0]);
        }

        int ct=0;
        for(int i=0; i<n; i++){
            if(ds.par[i]==i) ct++;
        }

        int ans=ct-1;

        return ans;
    }
};