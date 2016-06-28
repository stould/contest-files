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

int N;
int P[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    while (1) {
        int bi = 0;
        int bj = -1;
        
        for (int i = 0; i < N; i++) {
            int j = i;
            
            while (j + 1 < N && P[j] > P[j + 1]) {
                j += 2;
            }
            if (j - i + 1 > bj - bi + 1) {
                bi = i;
                bj = j;
            }
            i = j;
        }
        if (bi == bj) {
            break;
        }
        cout << bi + 1 << " " << bj << "\n";
        for (int i = bi; i < bj; i += 2) {
            swap(P[i], P[i + 1]);
        }
    }
    return 0;
}
