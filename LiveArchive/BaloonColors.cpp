#include <bits/stdc++.h>

using namespace std;

int T, N, X, Y;
int P[110];

int main() {
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> X >> Y;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        if (P[0] == X || P[N - 1] == Y) {
            if (P[0] == X && P[N - 1] == Y) {
                cout << "BOTH\n";
            } else {
                if (P[0] == X) {
                    cout << "EASY\n";
                } else {
                    cout << "HARD\n";
                }
            }
        } else {
            cout << "OKAY\n";            
        }
    }
    return 0;
}
