func averageWaitingTime(customers [][]int) float64 {
    sum := 0.0;
    end := float64(customers[0][0]);
    for _, customer := range customers {
        end = math.Max(end + float64(customer[1]), float64(customer[0]) + float64(customer[1]));
        sum += end - float64(customer[0]);
    }
    return sum / float64(len(customers));
}


