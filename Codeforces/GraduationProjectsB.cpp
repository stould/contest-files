#include <bits/stdc++.h>

using namespace std;

int N;
int P[200];

int main(void) {
    cin >> N;
    
    for (int i = 0; i < 2 * N; i++) {
        cin >> P[i];
    }
    
    sort(P, P + 2 * N);
    
    for (int i = 0; i < N; i++) {
        cout << P[i] << " " << P[2 * N - i - 1] << " ";
    }
    cout << "\n";
    return 0;
}
