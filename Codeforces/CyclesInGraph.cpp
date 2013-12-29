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

const int MAXN = 100005;

int N, M, K;
vector<int> graph[MAXN];

int vis[MAXN];
bool done;
int start, end;

vector<int> ans;

void dfs(int x, int curr) {
    if (done) return;

    vis[x] = curr;
    int i;

    ans.push_back(x);

    for (i = 0; i < (int) graph[x].size(); i++) {
        int u = graph[x][i];
        
        if (vis[u] == 0) {                        
            dfs(u, curr + 1);
        } 
    }

    done = true;
}

int main(void) {
    N = in();
    M = in();
    K = in();

    int i;

    for (i = 0; i < M; i++) {
        int A, B;

        A = in();
        B = in();

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (i = 0; i <= N; i++) {
        vis[i] = 0;
    }

    done = false;
    dfs(1, 1);

    start = ans[(int) ans.size() - 1];

    for (i = 0; i < (int) ans.size(); i++) {
        if (find(graph[start].begin(), graph[start].end(), ans[i]) != graph[start].end()) {
            end = i;
            break;
        }
    }
    
    printf("%d\n", (int) ans.size() - end);

    for (i = end; i < (int) ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}