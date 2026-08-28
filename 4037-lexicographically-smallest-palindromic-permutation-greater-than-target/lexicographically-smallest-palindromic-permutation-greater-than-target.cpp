class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        // Step 1 & 2: Validate palindrome and prepare our "Left Half" tiles
        int odd_count = 0;
        char mid_char = 0;
        vector<int> half_count(26, 0);
        
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i; // Lock in the middle character
            }
            half_count[i] = count[i] / 2;
        }

        // A palindrome can have at most one character with an odd frequency
        if (odd_count > 1) return ""; 

        string best_answer = "";
        string prefix = "";
        int left_len = n / 2;

        // Step 3: Walk through the left half of the target
        for (int i = 0; i <= left_len; i++) {
            
            if (i < left_len) {
                // --- PLAN A: DIVERGE (Try to place a bigger character here) ---
                char limit = target[i];
                for (int c = limit - 'a' + 1; c < 26; c++) {
                    if (half_count[c] > 0) {
                        string candidate = prefix + (char)('a' + c);
                        vector<int> letters_left = half_count;
                        letters_left[c]--;

                        // Dump remaining left-half letters in A-Z order
                        for (int j = 0; j < 26; j++) {
                            candidate.append(letters_left[j], 'a' + j);
                        }

                        // Mirror it to build the full palindrome
                        string full_palin = candidate;
                        if (n % 2 != 0) full_palin += mid_char; // Add middle if odd length
                        string right_half = candidate;
                        reverse(right_half.begin(), right_half.end());
                        full_palin += right_half;

                        // Overwrite previous answers (later divergence = tighter fit)
                        best_answer = full_palin;
                        break; 
                    }
                }

                // --- PLAN B: MATCH (Try to copy target[i] exactly) ---
                if (half_count[target[i] - 'a'] > 0) {
                    prefix += target[i];
                    half_count[target[i] - 'a']--;
                } else {
                    break; // If we can't match, we are stuck. Stop the loop.
                }
                
            } else if (i == left_len) {
                // --- Step 4: THE FULL MATCH CHECK ---
                // We perfectly copied the left half of target! Let's check the middle.
                if (n % 2 != 0) {
                    // Odd length: check if the forced middle character breaks us ahead
                    if (mid_char > target[i]) {
                        string full_palin = prefix + mid_char;
                        string right_half = prefix;
                        reverse(right_half.begin(), right_half.end());
                        full_palin += right_half;
                        best_answer = full_palin;
                    }
                    // If the middle matches, we must check the whole string
                    if (mid_char == target[i]) {
                        string full_palin = prefix + mid_char;
                        string right_half = prefix;
                        reverse(right_half.begin(), right_half.end());
                        full_palin += right_half;
                        if (full_palin > target) best_answer = full_palin;
                    }
                } else {
                    // Even length: no middle character, just check the mirrored string
                    string full_palin = prefix;
                    string right_half = prefix;
                    reverse(right_half.begin(), right_half.end());
                    full_palin += right_half;
                    if (full_palin > target) best_answer = full_palin;
                }
            }
        }

        return best_answer;
    }
};