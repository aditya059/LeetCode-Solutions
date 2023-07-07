func max(a, b int) int {
    if a > b {return a}
    return b
}

func maxConsecutiveAnswers(s string, k int) int {
    count := make(map[byte]int)
    var maxCount int = 0
    var ans int = 0
    for start, end := 0, 0; end < len(s); end++ {
        count[s[end]]++
        if maxCount < count[s[end]] {
            maxCount = count[s[end]]
        }
        for end - start + 1 - maxCount > k {
            count[s[start]]--
            start++
            maxCount = max(count['T'], count['F'])
        }
        ans = max(ans, end - start + 1)
    }
    return ans
}
