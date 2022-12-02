func maximumBinaryString(binary string) string {
    count := 0
    j := -1
    ans := make([]byte, len(binary));
    for i := len(binary) - 1; i >= 0; i-- {
        if binary[i] == '0' {
            count++
            j = i
        }
        ans[i] = '1'
    }
    if j != -1 {
        ans[j + count - 1] = '0';
    }
    return string(ans);
}