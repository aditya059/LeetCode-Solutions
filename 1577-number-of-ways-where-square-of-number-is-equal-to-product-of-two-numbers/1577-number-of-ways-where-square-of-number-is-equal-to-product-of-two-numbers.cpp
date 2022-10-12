class Solution {
public:
    int solve(vector<int>& A, vector<int>& B) {
        unordered_map<long, int> Map;
        for(int num: A) 
            Map[(long)num * num]++;
        int ans = 0;
        for(int k = 1; k < B.size(); k++) {
            for(int j = 0; j < k; j++) {
                ans += Map[(long)B[j] * B[k]];
            }
        }
        return ans;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans = solve(nums1, nums2) + solve(nums2, nums1);
        return ans;
    }
};