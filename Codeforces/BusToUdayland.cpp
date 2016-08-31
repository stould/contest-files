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

const int MAXN = 1010;

int N;
string S[MAXN];

int main(void) {
    cin >> N;

    bool fine = false;
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];

        if (!fine && S[i][0] == 'O' && S[i][1] == 'O') {
            S[i][0] = S[i][1] = '+';
            fine = true;
        }
        if (!fine && S[i][3] == 'O' && S[i][4] == 'O') {
            S[i][3] = S[i][4] = '+';
            fine = true;
        }
    }
    if (fine) {
        cout << "YES\n";
        for (int i= 0; i < N; i++) {
            cout << S[i] << "\n";
        }
    } else {
        cout << "NO\n";
    }
    return 0;    
}
