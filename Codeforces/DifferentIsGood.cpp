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

int N;
string S;

int main(void) {
    cin >> N >> S;

    if (N > 26) {
        cout << "-1\n";
    } else {
        map<char, bool> seen;

        int ans = 0;
        
        for (int i = 0; i < N; i++) {
            if (seen[S[i]]) {
                ans += 1;
            }
            seen[S[i]] = true;
        }
        cout << ans << "\n";
    }
    return 0;
}
