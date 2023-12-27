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


OR


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i = 0; i < colors.size(); i++) {
            int maxVal = neededTime[i], sum = neededTime[i];
            while(i < colors.size() - 1 && colors[i] == colors[i + 1]) {
                maxVal = max(maxVal, neededTime[i + 1]);
                sum += neededTime[i + 1];
                i++;
            }
            ans += sum - maxVal;
        }
        return ans;
    }
};
