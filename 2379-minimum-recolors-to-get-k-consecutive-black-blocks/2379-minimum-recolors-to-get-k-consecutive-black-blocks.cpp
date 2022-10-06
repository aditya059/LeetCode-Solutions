class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W')
                white++;
        }
        int ans = white;
        for(int i = k; i < blocks.size(); i++) {
            if(blocks[i] == 'W')
                white++;
            if(blocks[i - k] == 'W')
                white--;
            ans = min(ans, white);
        }
        return ans;
    }
};