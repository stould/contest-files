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

const int MAXN = 100010;

int N, M;
vector<int> G[MAXN];
bool reached[MAXN];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        G[A].push_back(B);
        G[B].push_back(A);
    }

    set<pair<int, int> > q;

    for (int i = 1; i <= N; i++) {
        if (!G[i].empty()) {
            q.insert(make_pair(G[i].size(), i));
        }
    }

    while (!q.empty()) {
        int now = (*q.begin()).second;

        int cp = 0;
        int id = -1;
        int ps = -1;
        int rev_ps = -1;

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];
            
            if (cp < (int) G[next].size()) {
                cp = (int) G[next].size();
                id = next;
                ps = i;
            }
        }

        for (int i = 0; i < (int) G[id].size(); i++) {
            if (G[id][i] == now) {
                rev_ps = i;
            }
        }
        
        if (!reached[now]) {
            reached[now] = true;
        } else {
            reached[id] = true;
        }
        
        q.erase(make_pair(G[id].size(), id));
        q.erase(make_pair(G[now].size(), now));

        G[now].erase(G[now].begin() + ps);
        G[id].erase(G[id].begin() + rev_ps);        
        
        if (!G[now].empty()) {
            q.insert(make_pair(G[now].size(), now));
        }
        
        if (!G[id].empty()) {
            q.insert(make_pair(G[id].size(), id));
        }

    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (!reached[i]) {
            ans += 1;
        }
    }

    cout << ans << "\n";
       
    
    return 0;
}
