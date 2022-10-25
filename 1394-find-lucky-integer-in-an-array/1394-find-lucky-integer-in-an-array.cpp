class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        for(int num: arr) {
            freq[num]++;
        }
        int ans = -1;
        for(int i = 1; i <= 500; i++) {
            if(i == freq[i])
                ans = i;
        }
        return ans;
    }
};