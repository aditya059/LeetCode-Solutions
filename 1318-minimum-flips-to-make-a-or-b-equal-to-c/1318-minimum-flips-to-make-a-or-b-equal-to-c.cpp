class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            bool A = (1 << i) & a;
            bool B = (1 << i) & b;
            bool C = (1 << i) & c;
            if(A && B && !C) ans += 2;
            else if(C && (A || B)) continue;
            else if(!A && !B && !C) continue;
            else ans++;
        }
        return ans;
    }
};