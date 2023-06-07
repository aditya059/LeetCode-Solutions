class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            bool A = (a >> i) & 1;
            bool B = (b >> i) & 1;
            bool C = (c >> i) & 1;
            if(A && B && !C) ans += 2;
            else if(C && (A || B)) continue;
            else if(!A && !B && !C) continue;
            else ans++;
        }
        return ans;
    }
};
