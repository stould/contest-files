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
 
const int MAXN = 110;
const int INF = 400;
 
int N;
int C[MAXN][MAXN], dist[MAXN];
int MN[MAXN];
 
int main(void) {
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> C[i][j];
        }
        dist[i] = INF;
    }
 
    for (int i = 0; i < N; i++) {
        cin >> MN[i];
    }
     
    priority_queue<pair<int, int> > q;
 
    q.push(make_pair(-MN[0], 0));
    dist[0] = MN[0];
     
    while (!q.empty()) {
        int curr_dist = -q.top().first;
        int node = q.top().second;
        q.pop();
		
        for (int i = 0; i < N; i++) {
            if (C[node][i]) {
                int best = max(curr_dist, MN[i]);
 
                if (dist[i] > best) {
                    dist[i] = best;
                    q.push(make_pair(-best, i));
                }
            }
        }
    }

    cout << dist[N-1] << "\n";
	
    return 0;
}
