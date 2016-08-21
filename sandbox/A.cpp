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
typedef unsigned long long uInt;
typedef unsigned uint;

int N;
double A, B;

int main(void) {
    cin >> A >> B >> N;

    double ans = 1000000000000000.0;
    
    for (int i = 0; i < N; i++) {
        double X, Y, V;
        cin >> X >> Y >> V;

        double dist = hypot(A - X, B - Y);

        chmin(ans, dist / V);
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;    
}
