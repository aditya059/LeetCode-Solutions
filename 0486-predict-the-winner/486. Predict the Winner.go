func max(a, b int) int {
    if a > b {return a}
    return b
}

func solve(i, j int, nums []int, memo [][]int) int {
    if i == j {return nums[i]}
    if memo[i][j] != -1 {return memo[i][j]}
    memo[i][j] = max(nums[i] - solve(i + 1, j, nums, memo), nums[j] - solve(i, j - 1, nums, memo))
    return memo[i][j]
}

func PredictTheWinner(nums []int) bool {
    n := len(nums)
    memo := make([][]int, n)
    for i := 0; i < n; i++ {
        memo[i] = make([]int, n)
        for j := 0; j < n; j++ {
            memo[i][j] = -1
        }
    }
    return solve(0, n - 1, nums, memo) >= 0
}
