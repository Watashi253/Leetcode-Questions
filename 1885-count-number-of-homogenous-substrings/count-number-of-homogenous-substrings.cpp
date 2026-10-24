class Solution {
public:
const int md=1e9+7;
    int countHomogenous(string s) {

        int n = s.size();
        int c = 0, op = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                c++;
            } else {
                c = 1;
            }
            op = (op + c) % md;
        }

        return op;
    }
};