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

const Int MOD = 1000000007LL;

string S;
unordered_map<int, Int> mp;

int value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 36;
    } else {
        if (c == '-') {
            return 62;
        } else {
            return 63;
        }
    }
}

int main(void) {
    cin >> S;

    Int ans = 1LL;

    for (int i = 0; i <= 63; i++) {
        Int cnt = 0LL;
        for (int a = 0; a <= 63; a++) {
            for (int b = 0; b <= 63; b++) {
                if ((a & b) == i) {
                    cnt += 1;
                }
            }
        }
        mp[i] = cnt;
    }
    
    
    for (int i = 0; i < (int) S.size(); i++) {
        int val = value(S[i]);
        Int cnt = mp[val];
        
     
        ans *= (Int) cnt;
        ans = ((ans % MOD) + MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
