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

int N, K;
string S;
uInt I;
string base = "";
int state = 1;
uInt dp[110][50][3];
int mm[110][50][3];

uInt func(int pos, int last, int match) {
    if (pos == (K + 1) / 2) {
        return 1LL;
    } else {
        uInt& ans = dp[pos][last][match];

        if (mm[pos][last][match] != state) {
            mm[pos][last][match] = state;
            ans = 0;

            for (int i = 0; i < N; i++) {
                if (S[i] > base[pos] && match) continue;                
                ans += func(pos + 1, i, match && S[i] == base[pos]);
            }
        }
        
        return ans;
    }
}

int main(void) {
    cin >> N >> S >> K >> I;

    for (int i = 0; i < (K + 1) / 2; i++) {
        base += S[0];
    }
 
    for (int i = 0; i < (K + 1) / 2; i++) {
        int best = 0;
        
        for (int m = 0; m < N; m++) {
            base[i] = S[m];
            
            uInt now = func(0, 27, 1);
            state += 1;
            //cout << base << " " << now << endl;
            if (now <= I) {
                best = m;
            }
        }
        base[i] = S[best];
    }

    for (int i = K / 2 - 1; i >= 0; i--) {
        base = base + base[i];
    }
    
    cout << base << endl;
    
    return 0;
}
