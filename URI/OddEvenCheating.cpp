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

int P, J1, J2, R, A;

int main(void) {
    cin >> P >> J1 >> J2 >> R >> A;

    P = 1 - P;
    
    if (R == 1) {
        if (A) {
            cout << "Jogador 2 ganha!" << endl;
        } else {
            cout << "Jogador 1 ganha!" << endl;
        }
    } else {
        if ((J1 + J2) % 2 == P) {
            cout << "Jogador 1 ganha!" << endl;
        } else {
            cout << "Jogador 2 ganha!" << endl;
        }
    }
    return 0;
}
