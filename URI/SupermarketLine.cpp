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

const int MAXN = 10005;

int N, M;
int P[MAXN], T[MAXN], C[MAXN];

int main(void) {
    cin >> N >> M;

    priority_queue<pair<int, int> > q;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        q.push(make_pair(0, -i));
    }

    int ans = 0;
    
    for (int i = 0; i < M; i++) {
        cin >> C[i];
        
        pair<int, int> now = q.top();
        q.pop();

        int tm = -now.first;
        int id = -now.second;
        ans = max(ans, tm);
        q.push(make_pair(-(tm + P[id] * C[i]), now.second));
    }

    while (!q.empty()) {
        ans = max(ans, -q.top().first);
        q.pop();
    }

    cout << ans << endl;
    return 0;
}
