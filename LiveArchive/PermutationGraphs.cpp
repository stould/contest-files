#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const int MAXN = 100005;

int T, N;
int A[MAXN];
int B[MAXN];
int P[MAXN];
Int bit[MAXN];

Int query(int pos) {
    Int ans = 0;

    for (int i = pos; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }

    return ans;
}

void update(int pos) {
    for (int i = pos; i <= N; i += (i & -i)) {
        bit[i] += 1;
    }
}
int main() {
    cin >> T;
  
    while (T--) {
        cin >> N;

        memset(bit, 0, sizeof(bit));
    
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            P[A[i]] = i;
        }
    
        Int ans = 0;

        for (int i = 1; i <= N; i++) {
            cin >> B[i];
            B[i] = P[B[i]];
            ans += (query(N) - query(B[i]));
            update(B[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
