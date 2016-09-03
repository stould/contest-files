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
            if (e.in) {
                sj = P[e.pos].first;
            } else {
                sj = P[e.pos].second;
            }
        } else {
            sj = K[pos];
        }
        if (si != sj) {
            return si < sj;
        } else {
            if (in != e.in) {
                return in > e.in;
            } else {
                return kind == 'l';
            }
        }
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
        }

        vector<int> ans(M, INF);

        sort(ve.begin(), ve.end());

        multiset<int> bL;
        multiset<int> bR;

        for (int i = 0; i < (int) ve.size(); i++) {
            int pos = ve[i].pos;

            if (ve[i].kind == 'c') {
                if (ve[i].in) {
                    bL.insert(P[pos].first);
                    bR.insert(P[pos].second);
                } else {
                    bL.erase(bL.find(P[pos].first));
                    bR.erase(bR.find(P[pos].second));
                }
            } else {
                auto la = bR.lower_bound(K[pos]);
                auto lb = bL.upper_bound(K[pos]);

                if (la != bR.end()) {
                    cout << K[pos] << " "<< *la << endl;
                    chmin(ans[pos], *la - K[pos]);
                }
                if (lb != bL.end()) {
                    chmin(ans[pos], K[pos] - *lb);
                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
