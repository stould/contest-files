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

const int MAXN = 110;

int N, A, B;
int M[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int a, int b) {
    return a >= 0 && b >= 0 && a < A && b < B;
}

bool check() {
    int p = 1;
    int q = 2;

    if (N % 2 == 0) {
        swap(p, q);
    }

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            if (i % 2 == j % 2) {
                if (p <= N) {
                    M[i][j] = p;
                    p += 2;
                }
            } else {
                if (q <= N) {
                    M[i][j] = q;
                    q += 2;
                }
            }
        }
    }

    bool valid = true;
    
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < 4; k++) {
                if (in(i + dx[k], j + dy[k]) && M[i + dx[k]][j + dy[k]] != 0 && M[i][j] % 2 == M[i + dx[k]][j + dy[k]]) {
                    valid = false;
                }
            }
        }
    }

    return valid;
}

int main(void) {
    cin >> N >> A >> B;

    if (N > A * B || !check()) {
        cout << "-1\n";
    } else {            
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                cout << M[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
