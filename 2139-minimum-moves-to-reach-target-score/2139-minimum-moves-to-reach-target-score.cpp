class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(target > 1) {
            if(target % 2 == 0 && maxDoubles) {
                ans++;
                maxDoubles--;
                target /= 2;
            }
            else {
                ans++;
                target--;
            }
            if(maxDoubles == 0)
                return ans + target - 1;
        }
        return ans;
    }
};