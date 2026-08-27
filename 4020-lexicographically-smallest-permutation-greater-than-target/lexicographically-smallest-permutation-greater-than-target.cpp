class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        string w="";
        string prefix = "";

        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }

        int ind=0;
        for(int i=0; i<target.size(); i++){

            // 1. Try to diverge at the current index
            if (i < s.length()){
                char limit = (i < target.length()) ? target[i] : 'a' - 1;

                for (int c = limit - 'a' + 1; c < 26; c++){
                    if (c >= 0 && freq[c] > 0){
                        string temp = prefix + (char)('a' + c);
                        vector<int> temp_freq=freq;

                        temp_freq[c]--;

                        for(int k=0; k<26; k++){
                            temp.append(temp_freq[k], 'a' + k);
                        }

                        w=temp;
                        break;
                    }
                }
            }

            // 2. Try to extend the matching prefix for the next iteration
            if (freq[target[i] - 'a'] > 0) {
                prefix += target[i];
                freq[target[i] - 'a']--;
            } else {
                break;
            }
        }

        return w;
    }
};