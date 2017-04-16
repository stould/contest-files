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

const int MAXN = 2501;

int N, M;
string S[60];
int name[60][60];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

vector<int> graph[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
        int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM(int limit) {
    int matchR[MAXN];
 
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 0; u < limit; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            //cout << "S " << u << endl;
            result++;
        }
    }
    return result;
}


int main(void) {
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }

        for (int i = 0; i < MAXN; i++) {
            graph[i].clear();
        }
        
        int cnt = 0;        
        int cntO = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] == '.') {
                    if ((i + j) % 2 == 0) {
                        name[i][j] = cnt++;
                    }
                }
            }
        }

        cntO = cnt;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] == '.') {
                    if ((i + j) % 2 == 1) {
                        name[i][j] = cntO++;
                    }
                }
            }
        }

                    
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] == '.') {
                    for (int k = 0; k < 2; k++) {
                        int pi = i + dx[k];
                        int pj = j + dy[k];
                        
                        if (pi >= 0 && pj >= 0 && pi < N && pj < M && S[pi][pj] == '.') {
                            graph[name[i][j]].push_back(name[pi][pj]);
                            graph[name[pi][pj]].push_back(name[i][j]);
                        }
                    }
                }
            }
        }
        //cout << 2 * maxBPM(cnt) << " " << cntO << endl;
        if (2 * maxBPM(cnt) == cntO) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
    }
     
    return 0;
}
