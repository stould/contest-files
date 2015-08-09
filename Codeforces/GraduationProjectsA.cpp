#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int N;
int P[MAXN], T[MAXN];

int main() {
    cin >> N;
    
    for (int i = 0; i < 2 * N; i++) {
        cin >> P[i];
    }

    double mean = 0.0;
    double ans = 0.0;
    
    int pos = 0;
    
    for (int i = 0; i < 2 * N; i += 2) {
        T[pos] = P[i] + P[i + 1];
        mean += T[pos];
        pos++;
    }

    mean /= (double) N;

    for (int i = 0; i < N; i++) {
        ans += fabs(T[i] - mean);
    }
    
    cout << fixed << setprecision(10) << ans << "\n";

    
    return 0;
}
