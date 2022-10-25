class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num: nums) {
            int root = sqrt(num);
            if(root * root == num) continue;
            int count = 0;
            int sum = 0;
            for(int i = 1; i <= root; i++) {
                if(num % i == 0) {
                    count += 2;
                    sum += i + num / i;
                }
            }
            if(count == 4)
                ans += sum;
        }
        return ans;
    }
};