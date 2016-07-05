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
const int INF = INT_MAX / 5;

string S;
vector<int> G[MAXN];
int V[MAXN];
int cntSize[MAXN];
int cntBall[MAXN];
int parent[MAXN];
int cnt;
bool valid;

int getNext() {
    return cnt++;
}

int dfsSize(int node) {
    cntSize[node] = G[node].empty() ? 1 : 0;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        cntSize[node] += dfsSize(next);    
    }
    
    return cntSize[node];
}

int dfsBall(int node) {
    cntBall[node] = V[node];
    
    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        cntBall[node] += dfsBall(next);        
    }
    
    return cntBall[node];
}

int dfs(int node, int offset) {
    if (G[node].empty()) {        
        return V[node] + offset <= 1 ? 0 : INF;
    } else {
        int ans = 0;
        
        for (int i = 0; i < (int) G[node].size(); i++) {
                ans += dfs(G[node][i], node);
            }
        }
        
        int& sA = cntBall[G[node][0]];
        int& sB = cntBall[G[node][1]];

        int df = (sA + sB) / 2;
        
        if ((sA + sB) % 2 == 0) {
            int addA = 0;
            int addB = 0;

            int la = 0;

            int lb = 0;
            
            la += abs(sA - df) + func(G[node][0], addA);            
            lb += abs(sB - df) + func(G[node][1], addB);

            return la + lb;
        } else {

        }
        
        if (abs(sA - sB) > 1) {


            if (abs(sA - sB) % 2 == 0 && df > 1) {
                df -= 1;
            }

            if (sA > sB) {
                if (cntSize[G[node][1]] - sB < df) {
                    valid = false;
                } else {
                    sA -= df;
                    sB += df;
                }
            } else {
                if (cntSize[G[node][0]] - sA < df) {
                    valid = false;
                } else {
                    sA += df;                
                    sB -= df;
                }
            }
            //cout << sA << " " << sB << " => " << cntSize[G[node][0]] << " " << cntSize[G[node][1]] << " \n\n";
            //cout << node << " " << sA << " " << sB << " => " << cntSize[G[node][0]] << " " << cntSize[G[node][1]] << " = " << df <<  "\n";
            ans += df;
        }

        return ans;
    }
}

int main(void) {
    while (cin >> S) {
        cnt = 1;
        
        for (int i = 0; i < MAXN; i++) {
            parent[i] = -1;
            V[i] = 0;

            cntSize[i] = 0;
            cntBall[i] = 0;
            
            G[i].clear();
        }

        int pos = 0;
        
        for (int i = 1; i < (int) S.size(); i++) {
            if (S[i] == '(') {
                int next = getNext();
                G[pos].push_back(next);
                parent[next] = pos;
                pos = next;
            } else if (S[i] == 'B') {
                V[pos] += 1;
                pos = parent[pos];
                i += 1;
            } else {
                pos = parent[pos];
            }

        }

        dfsSize(0);
        dfsBall(0);

        valid = true;

        int ans = dfs(0, 0);
        
        if (!valid) {
            cout <<"impossible\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
