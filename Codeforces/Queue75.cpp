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

const int MAXN = 100005;

int N;
pair<int, int> P[MAXN];

int main(void) {
    cin >> N;

    vector<int> ans(N, -1);
    
    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(P, P + N);

    int best = 0;

    for (int i = 0; i < N; i++) {
        ans[P[i].second] = max(-1, best - P[i].second - 1);
        best = max(best, P[i].second);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    
    return 0;
}
