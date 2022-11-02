class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int k = 0;
        for(uint32_t i = n; i >= 0 && k < 32; i /= 2) {
            k++;
            ans = ans * 2 + (i % 2); 
        }
        return ans;
    }
};