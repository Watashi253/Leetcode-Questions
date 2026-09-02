class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        int sum=1, up=0, down=0, peak=0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] == ratings[i - 1]) {
                sum+=1;
                up=0, down=0, peak=0;
            }

            else if(ratings[i] > ratings[i - 1]){
                up++;
                down = 0;
                peak=up;

                sum+=up+1;
            }

            else{
                down++;
                up=0;

                sum+=down;

                if (down > peak){
                    sum+=1;
                }
            }
        }

        return sum;
    }
};