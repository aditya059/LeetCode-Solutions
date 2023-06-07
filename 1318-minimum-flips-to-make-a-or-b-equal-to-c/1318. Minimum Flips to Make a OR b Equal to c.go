func minFlips(a int, b int, c int) int {
    ans := 0
    for i := 0; i < 32; i++ {
        A := ((a >> i) & 1) == 1 
        B := ((b >> i) & 1) == 1 
        C := ((c >> i) & 1) == 1 
        if A && B && !C {
            ans += 2
        } else if C && (A || B) {
            continue
        } else if !A && !B && !C {
            continue
        } else {
            ans++
        }
    }
    return ans
}
