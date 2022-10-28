class Solution {
public:
    static bool comp(string &A, string &B) {
        if(A.size() < B.size()) return true;
        else if(A.size() == B.size()) return A < B;
        return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size() - k];
    }
};