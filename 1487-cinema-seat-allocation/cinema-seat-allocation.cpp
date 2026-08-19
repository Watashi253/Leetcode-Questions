class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowToSeats;
        for (auto& seat : reservedSeats) {
            rowToSeats[seat[0]] |= (1 << seat[1]); 
        }
        int maxFamilies = 2 * n;
        for (auto& [row, seats] : rowToSeats){
            bool leftSafe   = (seats & 0b0000111100) == 0; 
            bool rightSafe  = (seats & 0b1111000000) == 0; 
            bool middleSafe = (seats & 0b0011110000) == 0;

            if (leftSafe && rightSafe) {
                continue; 
            } else if (leftSafe || rightSafe || middleSafe) {
                maxFamilies -= 1;
            } else {
                maxFamilies -= 2; 
            }
        }
        return maxFamilies;
    }
};