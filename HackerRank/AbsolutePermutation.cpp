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

const int MAXN = 100005;

int T, N, K;
int P[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        map<int, int> pos;
        
        for (int i = 0; i < N; i++) {
            P[i]   = i;
            pos[i] = i;
        }

        for (int i = 0; i < N; i++) {
            if (i + K < N && abs(i - pos[P[i + K]]) == K && abs(i + K - pos[P[i + K]]) == K) {
                swap(P[i], P[i + K]);
                swap(pos[P[i]], pos[P[i + K]]);
            }
        }

        for (int i = 0; i < N; i++) {
            cout << P[i] + 1 << " ";
        }
        cout << "\n";
        
    }
    return 0;
}
