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

int N, M;
vector<int> G[MAXN];
int color[MAXN];
bool ok;

void dfs(int x, int c) {
    color[x] = c;

    for (int i = 0; i < (int) G[x].size(); i++) {
        int next = G[x][i];

        if (color[next] == -1) {
            dfs(next, c ^ 1);
        } else if (color[next] == c) {
            ok = false;
        }
    }
}

int main(void) {
    cin >> N >> M;

    memset(color, -1, sizeof(color));
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        G[A].push_back(B);
        G[B].push_back(A);
    }

    ok = true;
    
    for (int i = 1; i <= N; i++) {
        if (color[i] == -1 && !G[i].empty()) {
            dfs(i, 1);
        }
    }

    if (ok) {
        vector<int> ia, ib;

        for (int i = 1; i <= N; i++) {
            if (color[i] == 1) {
                ia.push_back(i);
            } else if (color[i] == 0) {
                ib.push_back(i);
            }
        }
        cout << ia.size() << "\n";
        for (int i = 0; i < (int) ia.size(); i++) {
            cout << ia[i] << " ";
        }
        cout << "\n";
        cout << ib.size() << "\n";
        for (int i = 0; i < (int) ib.size(); i++) {
            cout << ib[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    
    return 0;
}
