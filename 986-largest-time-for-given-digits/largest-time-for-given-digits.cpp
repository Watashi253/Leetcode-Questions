class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string max_time = "";

        sort(arr.begin(), arr.end());
        do{
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];

            if (hours < 24 && minutes < 60){
                string current_time = to_string(arr[0]) + to_string(arr[1]) + 
                                      ":" + 
                                      to_string(arr[2]) + to_string(arr[3]);

                if (current_time > max_time) {
                    max_time = current_time;
                }
            }
        }while (next_permutation(arr.begin(), arr.end()));

        return max_time;
    }
};