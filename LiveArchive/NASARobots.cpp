#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 5;
int T, N;
string S;
int xm, ym, xma, yma;

int main() {    
    cin >> T;
    
    while (T--) {
        cin >> S;
        
        N = S.size();
        xm = INF; ym = INF; xma = -INF; yma = -INF;

        for (int x = 0; x < 4; x++) {                
            int cx = 0;
            int cy = 0;
            
            for (int i = 0; i < N; i++) {
                if(S[i] == 'R') {
                    cx += 1;
                } else if (S[i] == 'L') {
                    cx -= 1;
                } else if (S[i] == 'U') {
                    cy += 1;
                } else if (S[i] == 'D') {
                    cy -= 1;
                } else {
                    if (x == 0) {
                        cx -= 1;
                    } else if (x == 1) {
                        cx += 1;
                    } else if (x == 2) {
                        cy -= 1;
                    } else {
                        cy += 1;
                    }
                }            
            }
            xm = min(xm, cx);
            ym = min(ym, cy);
            xma = max(xma, cx);
            yma = max(yma, cy);
        }        
        printf("%d %d %d %d\n", xm, ym, xma, yma);
    }

    return 0;
}
