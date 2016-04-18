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

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 50505;
int T, N;
Int P[MAXN];
int pos[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        vector<pair<Int, Int> > q;
        int last = 0;
        Int ans = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            q.push_back(make_pair(P[i], i));
        }

        sort(q.rbegin(), q.rend());
        
        for (int i = 0; i < N; i++) {
            ans -= P[i];
            ans += q[last].first;
            
            if (q[last].second == i) {
                while (last < N && q[last].second <= i) {
                    last += 1;
                }
                if (last >= N) break;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
