func maximumUnits(boxTypes [][]int, truckSize int) int {
    var ans int = 0
    sort.Slice(boxTypes, func(i, j int) bool {
        return boxTypes[i][1] > boxTypes[j][1]
    })
    for _, boxType := range(boxTypes) {
        if boxType[0] <= truckSize {
            ans += boxType[1] * boxType[0]
            truckSize -= boxType[0]
        } else {
            ans += truckSize * boxType[1]
            break
        }
    }
    return ans
}