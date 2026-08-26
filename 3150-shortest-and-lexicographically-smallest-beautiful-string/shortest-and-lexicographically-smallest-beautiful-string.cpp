class Solution { 
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int min_len = INT_MAX;
        
        for (int i = 0; i < s.length(); i++) {
            int ones_count = 0;
            
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '1') {
                    ones_count++;
                }
                
                if (ones_count == k) {
                    int current_len = j - i + 1;
                    std::string current_sub = s.substr(i, current_len);
                    
                    if (current_len < min_len) {
                        min_len = current_len;
                        ans = current_sub;
                    } 
                    else if (current_len == min_len) {
                        if (current_sub < ans) {
                            ans = current_sub;
                        }
                    }
                } 
                else if (ones_count > k) {
                    break;
                }
            }
        }
        
        return ans;
    }
};