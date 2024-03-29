class Solution {
public:
    int dayOfYear(string date) {
        int d = stoi(date.substr(8, 2));
        int m = stoi(date.substr(5, 2));
        int y = stoi(date.substr(0, 4));
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < m; i++) {
            d += days[i - 1];
        }
        if((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && m > 2) d++;
        return d;
    }
};