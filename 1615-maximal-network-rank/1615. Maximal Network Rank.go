func max(a, b int) int {
  if a > b {return a}
  return b
}

func maximalNetworkRank(n int, roads [][]int) int {
      degree := make([]int, n)
      Map := make([][]int, n)
      for i := 0; i < n; i++ {
          Map[i] = make([]int, n)
      }
      for _, edge := range roads {
          degree[edge[0]]++
          degree[edge[1]]++
          Map[edge[0]][edge[1]] = 1
          Map[edge[1]][edge[0]] = 1
      }
      ans := 0
      for i := 0; i < n; i++ {
          for j := i + 1; j < n; j++ {
              ans = max(ans, degree[i] + degree[j] - Map[i][j])
          }
      }
      return ans
}
