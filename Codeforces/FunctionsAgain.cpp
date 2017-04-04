#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
long long P[MAXN];
long long df[MAXN];

long long func() {
    long long ans = 0;
    long long sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += df[i];
        if (sum < 0) {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    
    return ans;
}
int main() {
    cin >> N;

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (i > 0) {
            df[i] = abs(P[i] - P[i - 1]);
        }
        if (i % 2 == 0) {
            df[i] *= -1;
        }
    }

    ans = max(ans, func());
    for (int i = 0; i < N; i++) {
        df[i] *= -1;
    }
    ans = max(ans, func());
    
    cout << ans << "\n";
}
