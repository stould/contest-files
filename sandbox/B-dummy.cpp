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

Int N;

int main(void) {
    cin >> N;
    bool flag = false;
    for (Int a = 0; a * 1234 <= N && !flag; a++) {
        for (Int b = 0; a * 1234 + b * 123456 <= N && !flag; b++) {
            for (Int c = 0; c * 1234567 + b * 123456 + a * 1234 <= N && !flag; c++) {
                if (a * 1234 + b * 123456 + c * 1234567 == N) {
                    flag = true;
                }
            }
        }
    }
    cout << flag << "\n";
    return 0;
}
