func minimumAverageDifference(nums []int) int {
    var sum int64 = 0
    for _, num := range(nums) {
        sum += int64(num)
    }
    n := len(nums)
    ans := 0
    minAvg := math.MaxInt
    var currSum int64 = int64(nums[0])
    for i := 1; i < n; i++ {
        avg := int((currSum / int64(i)) - (sum - currSum) / int64(n - i));
        avg = int(math.Abs(float64(avg)))
        currSum += int64(nums[i]);
        if(avg < minAvg) {
            ans = i - 1;
            minAvg = avg;
        }
    }
    if(int(sum / int64(n)) < minAvg) {
        ans = n - 1;
    }
    return ans;
}

