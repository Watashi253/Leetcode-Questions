class Solution {
public:

int convertToDay(string date){
vector<int> daysPerMonth={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int nthDay = day;
        for (int i = 0; i < month - 1; i++) {
        nthDay += daysPerMonth[i];
    }

    return nthDay;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
         vector<int> days(366,0);

        int a1=convertToDay(arriveAlice);
        int a2=convertToDay(leaveAlice);
        int b1=convertToDay(arriveBob);
        int b2=convertToDay(leaveBob);

        for(int i=a1; i<=a2; i++){
            days[i]++;
        }

        for(int i=b1; i<=b2; i++){
            days[i]++;
        }

        int c=0;
        for(int i=1; i<366; i++){
            if(days[i]==2)c++;
        }

        return c;      
    }
};