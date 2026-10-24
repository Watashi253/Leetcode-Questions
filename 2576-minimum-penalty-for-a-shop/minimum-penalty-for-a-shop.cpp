class Solution {
public:
    int bestClosingTime(string customers) {
    int n=customers.size();
    int curr=0, maxc=0, hr=0;

    for(int i=0; i<n; i++){
        if(customers[i]=='Y') curr++;
        else curr--;

        if(curr>maxc){
            maxc=curr;
            hr=i+1;
        }
    }

    return hr;
    }
};