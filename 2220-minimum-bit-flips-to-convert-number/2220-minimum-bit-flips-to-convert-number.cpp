class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start xor goal;
        int count = 0;
        while(t) {
            count++;
            t = t - (t & -t);
        }
        return count;
    }
};