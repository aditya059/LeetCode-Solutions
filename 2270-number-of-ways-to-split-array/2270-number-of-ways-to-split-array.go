func waysToSplitArray(nums []int) int {
    var sum int64 = 0
    for _, num := range(nums) {
        sum += int64(num)
    }
    n := len(nums)
    ans := 0
    var currSum int64 = int64(nums[0])
    for i := 1; i < n; i++ {
        if(currSum >= sum - currSum) {
            ans++
        }
        currSum += int64(nums[i]);
    }
    return ans;
}