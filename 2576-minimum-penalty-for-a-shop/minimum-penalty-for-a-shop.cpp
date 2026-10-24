class Solution {
public:
    int bestClosingTime(string customers) {
    int n=customers.size();
    int minp=1e8,ind=-1, prefN=0;
    vector<int> sufY(n+1,0);
    sufY[n]=0;

    for(int i=n-1; i>=0; i--){
        sufY[i] = sufY[i+1];
        if(customers[i]=='Y')
        sufY[i]++;
    }

    for(int i=0; i<=n; i++){
        int p=prefN+sufY[i];
        if(i<n && customers[i]=='N') prefN++; 
        if(minp>p){
            minp=p;
            ind=i;
        }
    }

    return ind;
    }
};