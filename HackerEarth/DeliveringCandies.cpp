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
const Int INF = 10010100101001LL;

int N, M, S;
Int K[MAXN];
vector<pair<int, Int> > G[MAXN];
Int dist[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

void dijsktra(int source) {
    for(int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }
    priority_queue<int, vector<int>, MyLess> q;
    dist[source] = 0;
    q.push(source);

    while(!q.empty()) {
        int tmp = q.top(); q.pop();
        
        for(int i = 0; i < (int) G[tmp].size(); i++) {            
            Int aux_dist = dist[tmp] + G[tmp][i].second;
            Int actual_dist = dist[G[tmp][i].first];
            
            if(aux_dist < actual_dist) {
                dist[G[tmp][i].first] = aux_dist;
                q.push(G[tmp][i].first);
            }
        }
    }
}


int main(void) {
    cin >> N >> M >> S;

    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }

    for (int i = 0; i < M; i++) {
        int U, V, Q;

        cin >> U >> V >> Q;
        
        G[U].push_back(make_pair(V, Q));
        G[V].push_back(make_pair(U, Q));
    }

    dijsktra(S);

    vector<Int> ans(N + 1, 0);

    Int sum = 0;
    Int goSum = 0;
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] != INF) {
            sum += K[i];
            goSum += dist[i] * K[i];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] != INF) {
            ans[i] += dist[i] * (sum - K[i]);
            ans[i] += goSum - K[i] * dist[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
