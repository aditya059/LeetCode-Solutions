class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum[2] = {0};
        for(int i = 0; i < n; i++) {
            sum[i % 2] += nums[i];
        }
        for(int i = 0; i < n; i++) {
            sum[i % 2] -= nums[i];
            if(sum[0] == sum[1])
                ans++;
            sum[1 - (i % 2)] += nums[i];
        }
        return ans;
    }
};

/*
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int left[2] = {0};
        int right[2] = {0};
        for(int i = 0; i < n; i++) {
            right[i % 2] += nums[i];
        }
        for(int i = 0; i < n; i++) {
            right[i % 2] -= nums[i];
            if(left[0] + right[1] == left[1] + right[0])
                ans++;
            left[i % 2] += nums[i];
        }
        return ans;
    }
};
*/