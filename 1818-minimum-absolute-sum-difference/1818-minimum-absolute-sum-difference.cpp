class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();
        long totalDiff = 0;
        set<int> Set(nums1.begin(), nums1.end());
        for(int i = 0; i < n; i++) {
            totalDiff += abs(nums1[i] - nums2[i]);
        }
        long ans = totalDiff;
        for(int i = 0; i < n; i++) {
            auto iter = Set.upper_bound(nums2[i]);
            int mn = INT_MAX;
            if(iter != Set.end()) 
                mn = min(mn, abs(nums2[i] - *iter));
            if(iter != Set.begin())
                mn = min(mn, abs(nums2[i] - (*(--iter))));
            ans = min(ans, totalDiff - abs(nums1[i] - nums2[i]) + mn);
        }
        return ans % MOD;
    }
};