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

int A, B;

int main(void) {
    int t = 1;
    while (cin >> A) {
        if (A == 0) break;
        
        cin >> B;
        cout << "Instancia " << t++ << "\n";

        if ((A == 1 && B == 2) || (A == 2 && B == 3) || (A == 3 && B == 1)) {
            cout << "segundo\n\n";
        } else if ((B == 1 && A == 2) || (B == 2 && A == 3) || (B == 3 && A == 1)) {
            cout << "primeiro\n\n";
        } else {            
            cout << "empate\n\n";
        }
    }
    return 0;
}
