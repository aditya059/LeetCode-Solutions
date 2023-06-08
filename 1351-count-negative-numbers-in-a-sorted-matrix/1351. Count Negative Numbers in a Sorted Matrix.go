func countNegatives(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    j := n - 1
    count := 0
    for i := 0; i < m; i++ {
        for j >= 0 && grid[i][j] < 0 {j--}
        count += n - j - 1
    }
    return count
}
