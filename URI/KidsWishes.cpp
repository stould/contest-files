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
map<int, int> id;
int cnt;
vector<int> G[MAXN];
int vis[MAXN];
bool has_cycle, valid;
set<int> ss[MAXN];

int fix(int x) {
    if (id.find(x) == id.end()) {
        id[x] = cnt++;
    }
    return id[x];
}

int dfs(int x) {
    int ans = 1;
    int explored = 0;
    
    vis[x] = 1;

    for (int i = 0; i < (int) G[x].size(); i++) {
        //cout << x << " => " << G[x][i] << endl;
        if (vis[G[x][i]] == 0) {
            explored += 1;
            ans += dfs(G[x][i]);
        } else if (vis[G[x][i]] == 1) {
            has_cycle = true;
        }
    }

    vis[x] = 2;

    if (explored > 1) {
        valid = false;
    }
    return ans;
}
int main(void) {
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        cnt = 0;
        id.clear();
        has_cycle = false;
        valid = true;
        
        vector<pair<int, int> > st;
        vector<pair<int, int> >::iterator it;

        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;

            fix(A);
            fix(B);

            st.push_back(make_pair(A, B));
        }
        
        for (int i = 0; i < cnt; i++) {
            G[i].clear();
            ss[i].clear();
            vis[i] = 0;
        }
        
        for (it = st.begin(); it != st.end(); it++) {
            G[fix(it->first)].push_back(fix(it->second));
            G[fix(it->second)].push_back(fix(it->first));

            ss[fix(it->first)].insert(fix(it->second));
            ss[fix(it->second)].insert(fix(it->first));
        }

        int comp = 0;        
        int vis_cnt = 0;
                
        for (int i = 0; i < cnt; i++) {
            if (vis[i] == 0 && ss[i].size() == 1) {
                comp += 1;
                if (!G[i].empty()) {
                    vis_cnt += dfs(i);
                }              
            }
            if (ss[i].size() > 2) {
                valid = false;
            }
        }
        //cout << valid << " " << has_cycle << endl;
        if (!valid) {
            cout << "N";
        } else {
            //cout << has_cycle << " " << vis_cnt << endl;
            cout << has_cycle << endl;
            if (has_cycle) {
                if (vis_cnt == N && comp == 1) {                    
                    cout << "Y";
                } else {
                    cout << "N";
                }
            } else {
                cout << "Y";
            }
        }
        cout << endl;
    }
    return 0;
}
