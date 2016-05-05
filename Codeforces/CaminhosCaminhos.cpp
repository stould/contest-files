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

const int MAXN = 1000005;

int N, K;
int W[MAXN];

vector<pair<int, int> > G[MAXN];
int parent[MAXN], L[MAXN], vis[MAXN];
vector<int> level[MAXN];
int P[MAXN][20];

int id = 1;
int trie[MAXN][3];
int cnt[MAXN];

void add(string arg) {
    int pos = 0;
    
    for (int i = 0; i < (int) arg.size(); i++) {
        int now = arg[i] - '0';
        
        cnt[pos] += 1;

        if (trie[pos][now] == -1) {
            trie[pos][now] = id;
            pos = id++;            
        } else {
            pos = trie[pos][now];
        }
    }
}

int check(string K_str, string arg, int pos, int trie_pos, int is_eq, string buff) {
    if (pos == (int) arg.size()) {
        cout << buff << "\n" << arg << "\n\n";
        return cnt[trie_pos];
    } else {
        int val_arg = arg[pos] - '0';
        int val_k   = K_str[pos] - '0';
        
        int ans = 0;

        for (int i = 0; i <= 1; i++) {
            if (trie[trie_pos][val_arg ^ i] != -1) {
                int next = val_arg ^ i;
                
                if (next == val_k) {
                    ans += check(K_str, arg, pos + 1, trie[trie_pos][val_arg ^ i], is_eq, buff + char('0' + (val_arg ^ i)));
                } else if (next > val_k || (next < val_k && !is_eq)) {
                    ans += check(K_str, arg, pos + 1, trie[trie_pos][val_arg ^ i], false, buff + char('0' + (val_arg ^ i)));
                }
            }
        }

        return ans;
    }
}

void dfs(int pos, int par){
    if(parent[pos] == -1){
        parent[pos] = par;
		
        for(int i = G[pos].size() - 1,to;i >= 0;--i){
            to = G[pos][i].first;
            if(to != par) {
                dfs(to,pos);
            }
        }
    }
}

int get_level(int u){
    if(L[u]!=-1) return L[u];
    else if(parent[u]==-1) return 0;
    return 1+get_level(parent[u]);
}

void init() {
    for(int i = 0;i<N;++i) {
        L[i] = get_level(i);
    }

    for(int i = 0;i < N;++i) {
        level[L[i]].push_back(i);
    }

    memset(P,-1,sizeof(P));
	
    for(int i = 0; i < N; ++i) {
        P[i][0] = parent[i];
    }
	
    for(int j = 1; (1<<j) < N; ++j) {
        for(int i = 0; i < N; ++i) {
            if(P[i][j-1]!=-1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int p, int q) {
    if(L[p] < L[q]) {
        swap(p,q);
    }

    int log = 1;
    while((1<<log)<=L[p]) ++log;
    --log;

    for(int i = log;i>=0;--i)
        if(L[p]-(1<<i)>=L[q])
            p = P[p][i];

    if (p==q) return p;

    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }

    return parent[p];
}

string to_bin(int val) {
    string ans = "";

    for (int i = 30; i >= 0; i--) {
        if (val & (1 << i)) {
            ans += "1";
        } else {
            ans += "0";
        }
    }
    
    return ans;
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> W[i];

	vis[i] = 0;
	L[i] = parent[i] = -1;
	G[i].clear();
    }

    int A, B;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;

        A -= 1;
        B -= 1;
        
        G[A].push_back(make_pair(B, 0));
        G[B].push_back(make_pair(A, 0));
    }

    dfs(0, -2);
    parent[0] = -1;
    init();
        
    cin >> A >> B;

    A -= 1;
    B -= 1;
    
    int lca = LCA(A, B);

    vector<int> la, lb;

    while (A != lca) {
        la.push_back(W[A]);
        A = parent[A];
    }
    while (B != lca) {
        lb.push_back(W[B]);
        B = parent[B];
    }

    vector<int> all;

    for (int i = 0; i < (int) la.size(); i++) {
        all.push_back(la[i]);
    }
    all.push_back(W[lca]);
    for (int i = (int) lb.size() - 1; i >= 0; i--) {
        all.push_back(lb[i]);
    }

    Int ans = 0;
    int acc = 0;

    memset(trie, -1, sizeof(trie));

    string K_str = to_bin(K);

    for (int i = 0; i < (int) all.size(); i++) {
        acc ^= all[i];
        
        string curr = to_bin(acc);
        cout << curr << "\n\n";
        ans += check(K_str, curr, 0, 0, false, "");

        //cout << check(K_str, curr, 0, 0, false, "") << "\n";
        
        add(curr + '0');
        add(curr + '1');

        if (i > 0 && acc >= K) {
            ans += 1;
        }
    }

    if (all[0] >= K) ans += 1;

    cout << ans << "\n";
    
    return 0;
}
