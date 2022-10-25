class Solution {
public:
    int countLargestGroup(int n) {
        int mx = INT_MIN;
        int count[40] = {0};
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = i; j > 0; j /= 10) {
                sum += (j % 10);
            }
            mx = max(mx, ++count[sum]);
        }
        int ans = 0;
        for(int i = 1; i <= 36; i++) {
            if(mx == count[i])
                ans++;
        }
        return ans;
    }
};