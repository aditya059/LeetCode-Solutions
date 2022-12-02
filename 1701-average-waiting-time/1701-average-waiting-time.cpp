class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0.0;
        int end = customers[0][0];
        for(vector<int> customer: customers) {
            end = max(end + customer[1], customer[0] + customer[1]);
            sum += end - customer[0];
        }
        return sum / customers.size();
    }
};