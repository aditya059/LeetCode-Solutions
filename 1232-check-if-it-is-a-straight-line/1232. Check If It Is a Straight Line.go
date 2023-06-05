func checkStraightLine(coordinates [][]int) bool {
    diffX := coordinates[1][0] - coordinates[0][0]
    diffY := coordinates[1][1] - coordinates[0][1]
    for _, coor := range coordinates {
        if diffX * (coor[1] - coordinates[0][1]) != diffY * (coor[0] - coordinates[0][0]) {return false}
    }
    return true
}
