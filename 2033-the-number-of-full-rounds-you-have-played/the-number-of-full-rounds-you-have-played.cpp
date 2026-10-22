class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int startHour = stoi(loginTime.substr(0, 2));
        int startMin = stoi(loginTime.substr(3, 2));
        int login = (startHour * 60) + startMin;
        
        int endHour = stoi(logoutTime.substr(0, 2));
        int endMin = stoi(logoutTime.substr(3, 2));
        int logout = (endHour * 60) + endMin;

        if (login > logout) {
            logout += 1440; // Add 24 hours
        }

        int roundedLogin = (login + 14) / 15 * 15; 
        int roundedLogout = logout / 15 * 15;

        int rounds = (roundedLogout - roundedLogin) / 15;
        return max(0, rounds);
    }
};