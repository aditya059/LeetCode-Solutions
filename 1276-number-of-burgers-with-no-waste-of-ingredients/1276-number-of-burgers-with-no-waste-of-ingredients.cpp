class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int temp = tomatoSlices - 2 * cheeseSlices;
        if(temp < 0 || temp % 2) return {};
        int x = temp / 2;
        int y = cheeseSlices - x;
        if(y < 0) return {};
        return {x, y};
    }
};