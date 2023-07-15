func max(a, b int) int {
    if a > b {return a}
    return b
}

func binary_search(intervals [][]int, l, h, target int) int {
    ans := h + 1
    for l <= h {
        m := l + (h - l) / 2
        if target > intervals[m][0] {
            l = m + 1
        } else {
            if m < ans {ans = m}
            h = m - 1
        }
    }
    return ans
}

func maxValue(events [][]int, k int) int {
    n := len(events)
    sort.Slice(events, func(i int, j int) bool {
        return events[i][0] < events[j][0]
    })
    DP := make([][]int, 2)
    DP[0] = make([]int, n + 1)
    DP[1] = make([]int, n + 1)
    index := make([]int, n)
    for i := n - 1; i >= 0; i-- {
        DP[0][i] = max(DP[0][i + 1], events[i][2])
        index[i] = binary_search(events, i + 1, n - 1, events[i][1] + 1)
    }
    for i := 1; i < k; i++ {
        for j := n - 1; j >= 0; j-- {
            DP[i & 1][j] = max(DP[i & 1][j + 1], events[j][2] + DP[(i - 1) & 1][index[j]])
        }
    }
    return DP[(k - 1) & 1][0]
}
