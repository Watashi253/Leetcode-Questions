class Solution {
public:
    string frequencySort(string s) {

        map<char, int> check;
        for(char c:s){
            check[c]++;
        }

        string temp="";
        vector<pair<char, int>> cnt(check.begin(), check.end());
        sort(cnt.begin(), cnt.end(), [](const auto& a, const auto& b){
           return a.second>b.second;
        });

        for(int i=0; i<cnt.size(); i++){
            while(cnt[i].second!=0){
                temp+=cnt[i].first;
                cnt[i].second--;
            }
        }

        return temp;
    }
};