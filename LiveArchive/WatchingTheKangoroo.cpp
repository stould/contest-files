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
typedef unsigned uint;

const int MAXN = 100007;
const int INF = INT_MAX / 2;

int T, N, M;
pair<int, int> P[MAXN];
int K[MAXN];

struct event {
    char kind;
    int in, pos;

    event(char kind, int in, int pos): kind(kind), in(in), pos(pos) {}

    bool operator<(const event& e) const {
        int si = 0;
        int sj = 0;

        if (kind == 'c') {
            if (in) {
                si = P[pos].first;
            } else {
                si = P[pos].second;
            }
        } else {
            si = K[pos];
        }
        
        if (e.kind == 'c') {
            sj = K[pos];
        }

        
        return si < sj;
    }
};

vector<event> ve;    

int main(void) {
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &N, &M);
				
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &P[i].first, &P[i].second);
            ve.push_back(event('c', 1, i));
            ve.push_back(event('c', 0, i));
        }

        printf("Case %d:\n", t);

        for (int i = 0; i < M; i++) {
            scanf("%d", &K[i]);
            ve.push_back(event('l', 1, i));
            ve.push_back(event('l', 0, i));
        }

        sort(ve.begin(), ve.end());
    }
    return 0;
}
