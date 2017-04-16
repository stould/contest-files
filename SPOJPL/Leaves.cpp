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

const int MAXN = 100050;

int N, K;
int dp[MAXN][15];
int sum[MAXN];
int ksum[MAXN];

struct Line {
    Int m, b;
    mutable function<const Line*()> succ;

    bool operator<(const Line& rhs) const {
        if (rhs.b != INF) {
            //invert operator to get minimum
            return m < rhs.m;
        }
        const Line* s = succ();
        if (!s) {
            return 0;
        }
        Int x = rhs.m;
        //invert operator to get minimum
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> {  // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) {
            return y->m == x->m && y->b <= x->b;
        }
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(Int m, Int b) {
        auto y = insert({ m, b });
        
        y->succ = [=] { 
            return next(y) == end() ? 0 : &*next(y); 
        };
        if (bad(y)) { 
            erase(y); 
            return; 
        }
        
        while (next(y) != end() && bad(next(y))) {
            erase(next(y));
        }
        while (y != begin() && bad(prev(y))) {
            erase(prev(y));
        }
    }
    Int eval(Int x) {
        auto l = *lower_bound((Line) {x, INF});
        return l.m * x + l.b;
    }
};

int main(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    
    reverse(P + 1, P + N + 1);
    
    for (int i = 1; i <= N; i++) {
        dp[i][1] = 0;
        
        sum[i] = sum[i - 1] + P[i];
        ksum[i] = ksum[i - 1] + P[i] * i;
    }

    for (int k = 2; k <= K; k++) {
        HullDynamic trick;
        
        trick.insert_line(def[0].second, 0);
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1]);
            }
        }
    }
    return 0;
}
