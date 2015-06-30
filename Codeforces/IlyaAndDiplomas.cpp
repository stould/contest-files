#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N;
int L[5], R[5];

int main(void) {
    cin >> N;

    vector<int> ans(3);
    
    for (int i = 0; i < 3; i++) {
        cin >> L[i] >> R[i];
        ans[i] = R[i];
    }
    if (ans[0] + ans[1] + ans[2] == N) goto end;
    if (ans[2] > L[2]) {
        if (ans[0] + ans[1] + L[2] <= N) {
            ans[2] = N - ans[0] - ans[1];
        } else {
            ans[2] = L[2];
        }
    }
    if (ans[0] + ans[1] + ans[2] == N) goto end;
    if (ans[1] > L[1]) {
        if (ans[0] + L[1] + ans[2] <= N) {
            ans[1] = N - ans[0] - ans[2];
        } else {
            ans[1] = L[1];
        }
    }
    ans[0] = N - ans[1] - ans[2];
    
 end:;
    cout << ans[0] << " "<< ans[1] << " " << ans[2] <<"\n";
    
    return 0;
}
