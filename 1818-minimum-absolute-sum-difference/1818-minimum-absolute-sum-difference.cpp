class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();
        long totalDiff = 0;
        set<int> Set(nums1.begin(), nums1.end());
        int mn = INT_MIN;
        for(int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            totalDiff += diff;
            auto iter = Set.upper_bound(nums2[i]);
            if(iter != Set.end()) 
                mn = max(mn, diff - abs(nums2[i] - *iter));
            if(iter != Set.begin())
                mn = max(mn, diff - abs(nums2[i] - *prev(iter)));
        }
        return (totalDiff - mn) % MOD;
    }
};