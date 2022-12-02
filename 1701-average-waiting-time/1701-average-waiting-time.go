func averageWaitingTime(customers [][]int) float64 {
    var sum int = 0;
    var end int = customers[0][0];
    for _, customer := range customers {
        end = int(math.Max(float64(end + customer[1]), float64(customer[0] + customer[1])));
        sum += end - customer[0];
    }
    return float64(sum) / float64(len(customers));
}


