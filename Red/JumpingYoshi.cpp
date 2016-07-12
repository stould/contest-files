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

const int MAXN = 2000005;
const int INF = INT_MAX / 5;

int N;
int P[MAXN];
int dist[MAXN];
unordered_map<int, vector<int> > reach;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N && N != 0) {
        reach.clear();
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];

            dist[i] = INF;
            
            if (i - P[i] >= 0) {
                reach[i - P[i]].push_back(i);
            }
            if (i + P[i] < N) {
                reach[i + P[i]].push_back(i);
            }
        }

        queue<int> q;
        q.push(0);

        dist[0] = 0;
        
        int ans = 0;
        
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            ans = max(ans, now);
            
            if (now + P[now] < N) {
                for (int i = 0; i < (int) reach[now + P[now]].size(); i++) {
                    int next = reach[now + P[now]][i];
                    int ds   = 1;;

                    if (dist[next] > dist[now] + ds) {
                        dist[next] = dist[now] + ds;
                        q.push(next);
                    }
                }
            }
            if (now - P[now] >= 0) {
                for (int i = 0; i < (int) reach[now - P[now]].size(); i++) {
                    int next = reach[now - P[now]][i];
                    int ds   = 1;

                    if (dist[next] > dist[now] + ds) {
                        dist[next] = dist[now] + ds;
                        q.push(next);
                    }
                }
            }
        }
        
        cout << ans << endl;
    }
    return 0;    
}
