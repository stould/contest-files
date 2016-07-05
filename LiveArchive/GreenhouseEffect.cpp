#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50050;

int N, M;
int P[MAXN], dp[MAXN];
double dummy;

int main() {
    cin >> N >> M;
   
    for (int i = 0; i < N; i++) {
        scanf("%d%lf", &P[i], &dummy);
    }
   
    int ans = 0;
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (P[i] >= P[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                ans = max(ans, dp[i]);
            }
        }
    }
   
    cout << N - (ans + 1) << "\n";
   
    return 0;
}
