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

int main(void) {
    while (cin >> N) {
        double J = 0;
        double T = 0;
        
        for (int i = 0; i < N; i++) {
            double buff;
            cin >> buff;

            if (i % 3 != 0) {
                J += buff;
            } else {
                T += buff;
            }
        }

        cout << fixed << setprecision(2) << "Junior: R$" << J << "\n";
        cout << fixed << setprecision(2) << "Thiago: R$" << T << "\n";
    }
    return 0;
}
