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

Int A, B;
string S;
Int dp[80][5][80][5];

string to_bin(Int val) {
    string ans = "";

    if (val == 0) return "";

    while (val > 0) {
        char now = '0' + (val % 2);
        ans = now + ans;
        val /= 2;
    }
    
    return ans;
}

Int func(int pos, int last, int used, bool pref) {
    if (pos == (int) S.size()) {
        return used;
    } else {
        Int& ans = dp[pos][last][used][pref];

        if (ans == -1) {
            ans = 0;
            ans = func(pos + 1, 0, used, pref && S[pos] == '0');
            
            if (S[pos] == '1' or !pref) {
                ans += func(pos + 1, 1, used + 1, pref && S[pos] == '1');
            }
        }

        return ans;
    }
}

int main(void) {
    while (cin >> A >> B) {
        Int ans = 0;

        S = to_bin(B);

        memset(dp, -1, sizeof(dp));
        ans += func(0, 0, 0, 1);

        
        S = to_bin(A - 1);
        //cout << S << endl;
        memset(dp, -1, sizeof(dp));
        ans -= func(0, 0, 0, 1);
        
        cout << ans << endl;
    }
    return 0;
}
