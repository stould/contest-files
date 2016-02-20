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

const int MAXN = 220;

int N;
string S;
pair<int, int> P[MAXN];

int main(void) {
    cin >> N >> S;
    
    int ans = 0;
    
    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; i++) {        
        if (S[i] == 'U') {
            Y += 1;
        } else if (S[i] == 'D') {
            Y -= 1;
        } else if (S[i] == 'L') {
            X += 1;
        } else {
            X -= 1;
        }
        P[i] = make_pair(X, Y);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int px = P[j].first;
            int py = P[j].second;
			
            if (i != 0) {
                px -= P[i - 1].first;
                py -= P[i - 1].second;
            }

            if (px == 0 && py == 0) {
                ans += 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
