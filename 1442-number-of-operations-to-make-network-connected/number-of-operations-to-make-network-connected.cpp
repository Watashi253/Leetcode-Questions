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

    bool unionbySize(int u, int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU==rootV) return false;

        if(size[rootU]<size[rootV]){
            par[rootU]=rootV;
            size[rootV]+=size[rootU];
        }
        else{
            par[rootV]=rootU;
            size[rootU]+=size[rootV];
        }
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet ds(n);

        int components = n;
        for(auto c: connections){
            if(ds.unionbySize(c[1], c[0]))
            components--;
        }
        
        return components - 1;
    }
};