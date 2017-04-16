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
Int N;

int main(void) {
    cin >> S >> N;

    Int ans = 0;
    int L = (int) S.size();
    
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == 'a') {
            Int l = 0, h = 100000000000000LL;
            Int pos = -1;
            
            while (l <= h) {
                Int m = l + (h - l) / 2;
                //cout << m << " " << i + L * m << "\n";
                if (1 + i + L * m <= N) {
                    pos = m + 1;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }

            ans += pos;
        }        
    }
    cout << ans << "\n";
    return 0;
}
