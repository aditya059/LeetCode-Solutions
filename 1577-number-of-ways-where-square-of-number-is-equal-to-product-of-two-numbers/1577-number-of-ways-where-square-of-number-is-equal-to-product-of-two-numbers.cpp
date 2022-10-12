class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long, int> Map1;
        unordered_map<long, int> Map2;
        for(int num: nums1) 
            Map1[(long)num * num]++;
        for(int num: nums2)
            Map2[(long)num * num]++;
        int ans = 0;
        for(int k = 1; k < nums1.size(); k++) {
            for(int j = 0; j < k; j++) {
                ans += Map2[(long)nums1[j] * nums1[k]];
            }
        }
        for(int k = 1; k < nums2.size(); k++) {
            for(int j = 0; j < k; j++) {
                ans += Map1[(long)nums2[j] * nums2[k]];
            }
        }
        return ans;
    }
};