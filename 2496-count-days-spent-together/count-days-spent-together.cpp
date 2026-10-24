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

        int a1=convertToDay(arriveAlice);
        int a2=convertToDay(leaveAlice);
        int b1=convertToDay(arriveBob);
        int b2=convertToDay(leaveBob);

        int start=max(a1, b1);
        int end = min(a2, b2);

        return max(0, end-start+1);      
    }
};