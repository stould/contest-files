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

int T, N;
int P[110];

int win(vector<int> x, int len) {
    if (x[0] == len) {
        return 0;
    } else {
        for (int i = 1; i < (int) x.size(); i++) {
            if (x[i] > 0) {
                for (int k = 0; k < i; k++) {
                    vector<int> next = x;
                    next[i] -= 1;
                    next[k] += 1;

                    if (!win(next, len)) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }    
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        Int s = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            s += (i + 1) * (Int) P[i];
        }

        if (s % 2 == 1) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
