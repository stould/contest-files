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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1000005;

int T, N;
set<int> seen;
vector<int> G[MAXN];
int deg[MAXN];

vector<int> func(void) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > q;
    
    for (auto it : seen) {
        if (deg[it] == 0) {
            q.push(it);
        }
        sort(G[it].begin(), G[it].end());
    }

    while (!q.empty()) {
        int now = q.top();
        q.pop();

        ans.push_back(now);

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];

            deg[next] -= 1;
            
            if (deg[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return ans;
}

int main(void) {
    cin >> T;

    vector<int> curr;
    
    for (int i = 0; i < T; i++) {
        cin >> N;

        int now, last = -1;
        
        for (int j = 0; j < N; j++) {
            cin >> now;

            seen.insert(now);
            
            if (j > 0) {
                G[last].push_back(now);
                deg[now] += 1;
            }
            
            last = now;
        }
    }

    vector<int> ans = func();

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
