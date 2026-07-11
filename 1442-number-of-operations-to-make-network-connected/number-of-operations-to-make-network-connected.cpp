class DisjointSet {
public:
vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n,1);
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

    void unionbySize(int u, int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU==rootV) return;
        if(size[rootU]<size[rootV]){
            par[rootU]=rootV;
            size[rootV]+=size[rootU];
        }
        else{
            par[rootV]=rootU;
            size[rootU]+=size[rootV];
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
            ds.unionbySize(c[1], c[0]);
        }

        int ct=0;
        for(int i=0; i<n; i++){
            if(ds.par[i]==i) ct++;
        }

        int ans=ct-1;

        if(extract < ans) return -1;
        return ans;
    }
};