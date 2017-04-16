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

string S;
Int K;

int main(void) {
    cin >> S >> K;

    int N = (int) S.size();
    
    for (int i = 0; i < N; i++) {
        int cost = 'z' - S[i] + 1;
        if (K >= cost) {
            S[i] = 'a';
            K -= cost;
        }
    }
    
    bool good = false;
    
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] != 'a') {
            int ps = S[i] - 'a';
            ps += K;
            ps %= 26;
            
            
            S[i] = 'a' + ps;
            good = true;
            K = 0;
            break;
        }
    }

    if (!good) {
        int ps = S[N - 1] - 'a';
        ps += K;
        ps %= 26;        
        
        S[N - 1] = 'a' + ps;
    }
    
    cout << S << endl;
    
    return 0;
}
