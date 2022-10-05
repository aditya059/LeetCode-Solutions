class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, dist = 0;
        for(int i = 0; i < distance.size(); i++)
            sum += distance[i];
        for(int i = min(start, destination); i < max(start, destination); i++) {
            dist += distance[i];
        }
        return min(dist, sum - dist);
    }
};