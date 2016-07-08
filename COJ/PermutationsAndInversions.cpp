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

int N, K;
int P[MAXN];
//6 5 3 4 2 1
int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        P[i] = i + 1;
    }

    int pos = 0;
    
    while (K > 0) {
        if (pos == 0) {
            if (K - N - 1 >= 0) {
                swap(P[pos], P[N - pos - 1]);
                K -= N - 1;
            } else {
                swap(P[pos], P[pos + K]);
                K = 0;
            }
        } else {
            
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    return 0;
}
