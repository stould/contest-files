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

const int MAXN = 200;
const int ALPHA_SIZE = 26;

int N, M;
string S;
Int dp[ALPHA_SIZE][MAXN][1 << 10];
bool seen[ALPHA_SIZE][MAXN][1 << 10];
int T[MAXN], sig[MAXN][ALPHA_SIZE], cnt;
vector<int> term[MAXN];
vector<string> ansStr;

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) (arg[i] - 'a');

        if (sig[x][c] == 0) {
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    
    term[x].push_back(id);
}


void aho() {
    queue <int> Q;
    
    for (int i = 0; i < ALPHA_SIZE; i++){
        int v = sig[0][i];

        if (v) {
            Q.push (v);
            T[v] = 0;
        }
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        
        for (int i = 0; i < ALPHA_SIZE; i++){
            int x = sig[u][i];

            if (x == 0) {
                continue;
            }
            
            int v = T[u];

            while (sig[v][i] == 0 && v != 0) {
                v = T[v];
            }

            int y = sig[v][i];
            Q.push(x);
            T[x] = y;

            for (int j = 0; j < (int) term[y].size(); j++) {                
                term[x].push_back(term[y][j]);
            }
        }
    }
}


Int func(int pos, int trie_pos, int mask) {
    if (pos == N) {
        return mask == ((1 << M) - 1) ? 1LL : 0LL;
    } else {
        Int& ans = dp[pos][trie_pos][mask];
        
        if (seen[pos][trie_pos][mask] == false) {
            seen[pos][trie_pos][mask] = true;
            
            ans = 0LL;

            for (int i = 0; i < 26; i++) {
                int next_pos = trie_pos;

                while (next_pos != 0 && sig[next_pos][i] == 0) {
                    next_pos = T[next_pos];
                }
                
                next_pos = sig[next_pos][i];            
                
                int next_mask = mask;

                for (int j = 0; j < (int) term[next_pos].size(); j++) {
                    next_mask |= (1 << term[next_pos][j]);
                }
                if (!term[next_pos].empty()) {                    
                    ans += func(pos + 1, 0, next_mask);
                } else {
                    ans += func(pos + 1, next_pos, next_mask);
                }
            }
        }

        return ans;
    }
}

void rec(int pos, int trie_pos, int mask, string arg) {
    if (pos == N) {
        if (mask == ((1 << M) - 1)) {
            ansStr.push_back(arg);
        }
    } else {
        for (int i = 0; i < 26; i++) {
            int next_pos = trie_pos;
            
            while (next_pos != 0 && sig[next_pos][i] == 0) {
                next_pos = T[next_pos];
            }
            
            next_pos = sig[next_pos][i];            
            
            int next_mask = mask;
            
            for (int j = 0; j < (int) term[next_pos].size(); j++) {
                next_mask |= (1 << term[next_pos][j]);
            }
            if (!term[next_pos].empty()) {                
                if (func(pos + 1, 0, next_mask) > 0) {
                    rec(pos + 1, 0, next_mask, arg + char('a' + i));
                }
            } else {
                if (func(pos + 1, next_pos, next_mask) > 0) {
                    rec(pos + 1, next_pos, next_mask, arg + char('a' + i));
                }
            }
        }
    }
}


bool contains(string a, string b) {
    if (b.size() > a.size()) return false;

    for (int i = 0; i + b.size() < a.size(); i++) {
        if (b == a.substr(i, b.size())) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int test = 1;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        cnt = 1;
        memset(sig, 0, sizeof(sig));

        for (int i = 0; i < MAXN; i++) {
            term[i].clear();
        }

        vector<string> buffer(M), fixed;
        vector<bool> used(M, false);
        
        for (int i = 0; i < M; i++) {
            cin >> buffer[i];
        }
        for (int i = 0; i < M; i++) {
            if (!used[i]) {
                for (int j = 0; j < M; j++) {
                    if (i != j && !used[j] && contains(buffer[j], buffer[i])) {
                        used[i] = true;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (!used[i]) {
                fixed.push_back(buffer[i]);
            }
        }

        M = (int) fixed.size();

        for (int i = 0; i < M; i++) {
            add(fixed[i], i);
        }

        aho();

        memset(seen, false, sizeof(seen));

        Int ans = func(0, 0, 0);
        
        cout << "Case " << test++ << ": " << ans << " suspects\n";

        if (ans > 0 && ans <= 42) {
            ansStr.clear();
            rec(0, 0, 0, "");

            sort(ansStr.begin(), ansStr.end());
            
            for (int i = 0; i < (int) ansStr.size(); i++) {
                cout << ansStr[i] << "\n";
            }
        }
    }
    return 0;
}
