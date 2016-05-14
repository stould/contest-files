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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N;
string S[110];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'C') {
                for (int k = i + 1; k < N; k++) {
                    if (S[k][j] == 'C') {
                        ans += 1;
                    }
                }
                for (int k = j + 1; k < N; k++) {
                    if (S[i][k] == 'C') {
                        ans += 1;
                    }
                }

            }
        }
    }

    cout << ans << "\n";
    return 0;
}
