#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T, N, M;
int P[MAXN][MAXN];
int S[MAXN][MAXN];
int main() {
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> P[i][j];
                
                S[i][j] = P[i][j];
                
                S[i][j] += S[i][j - 1];
            }
        }
        
        int best = -INT_MAX;
        
        for (int i = M; i >= 1; i--) {
            int curr = 0;
            for (int j = N; j >= 1; j--) {
                int bef = curr;
                curr += S[j][M] - S[j][i - 1];
                best = max(best, curr);
                if (curr < bef) {
                    break;
                }
            }
        }
        
        cout << best << "\n";
    }
    return 0;
}
