class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int currtime = neededTime[0];
        int ans = 0;
        int sum = neededTime[0];
        for(int i = 1; i < colors.size(); i++) {
            sum += neededTime[i];
            if(colors[i] == colors[i - 1]) {
                currtime = max(neededTime[i], currtime);
            }   
            else {
                ans += currtime;
                currtime = neededTime[i];
            }
        }
        ans += currtime;
        return sum - ans;
    }
};