#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
int N;

int main() {
    cin >> N;

    double prob = 1;

    for (int i = 1; i <= N; i++) {
        prob *= (1 - (i / (double) N));
        
        if ((1 - prob) + EPS > 0.5) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}
