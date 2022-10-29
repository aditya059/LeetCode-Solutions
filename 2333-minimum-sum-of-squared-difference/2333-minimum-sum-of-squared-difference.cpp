class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        k1 += k2;
        int maxDiff = 0;
        for(int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, nums1[i]);
        }
        vector<int> count(maxDiff + 1);
        for(int i = 0; i < n; i++) count[nums1[i]]++;
        for(int i = maxDiff; i > 0 && k1 > 0; i--) {
            int sub = min(k1, count[i]);
            count[i] -= sub;
            count[i - 1] += sub;
            k1 -= sub;
        }
        long long ans = 0;
        for(int i = 1; i <= maxDiff; i++) {
            ans += 1L * count[i] * i * i;
        }
        return ans;
    }
};