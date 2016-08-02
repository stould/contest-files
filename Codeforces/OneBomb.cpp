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

const int MAXN = 1010;

int N, M;
string S[MAXN];
int R[MAXN], C[MAXN];

int main(void) {
    cin >> N >> M;

    int all = 0;

    for (int i = 0; i < N; i++) {
        cin >> S[i];

        for (int j = 0; j < M; j++) {
            if (S[i][j] == '*') {
                R[i] += 1;
                C[j] += 1;

                all += 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (R[i] + C[j] - (S[i][j] == '*' ? 1 : 0)== all) {
                cout << "YES\n";
                cout << i + 1<< " " << j + 1<< "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
