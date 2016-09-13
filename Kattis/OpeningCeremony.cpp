#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
int P[MAXN];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    int ans = N;
  
    for (int i = 0; i < N; i++) {
        ans = min(ans, P[i] + (N - i - 1));
    }
  
    cout << ans << "\n";
    return 0;
}

