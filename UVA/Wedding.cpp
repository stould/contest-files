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

const int MAXN = 500;

int N, M;
vector<int> G[MAXN], R[MAXN];
bool vis[MAXN];
int comp[MAXN];
vector<int> order;

void addNot(int a, int b) {
    G[a ^ 1].push_back(b);
    R[b].push_back(a ^ 1);

    G[b ^ 1].push_back(a);
    R[a].push_back(b ^ 1);
}

int realValue(string arg) {
    int ans = stoi(arg.substr(0, arg.size() - 1));

    if (arg.back() == 'w') {
        ans += N;
    }

    ans *= 2;

    return ans;
}

string retrieveValue(int arg) {
    char kind = arg >= N ? 'w' : 'h';
    int value = arg < N ? arg : arg - N;
    
    return to_string(value) + kind;
}

void dfs(int node) {
    vis[node] = true;

    for (auto& it : G[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
    
    order.push_back(node);
}

void dfsRev(int node, int cp) {
    vis[node] = true;
    comp[node] = cp;
    

    for (auto& it : R[node]) {
        if (!vis[it]) {
            dfsRev(it, cp);
        }
    }
}

bool twoSat() {
    memset(vis, false, sizeof(vis));
    order.clear();
    
    for (int i = 2; i < 4 * N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, false, sizeof(vis));
    int curr_comp = 1;
    
    for (int i = (int) order.size() - 1; i >= 0; i--) {
        if (!vis[order[i]]) {
            dfsRev(order[i], curr_comp++);
        }
    }
    
    for (int i = 2; i < 4 * N; i += 2) {
        if (comp[i] == comp[i ^ 1]) {
            return false;
        }
    }
    return true;
}

vector<string> retrievePath() {
    vector<string> ans;
    set<int> st;
    
    memset(vis, false, sizeof(vis));
    
    for (int i = 0; i < (int) order.size(); i++) {
        int now = order[i];

        string arg = retrieveValue(now / 2);
        int toi = stoi(arg.substr(0, arg.size() - 1));

        cout << now << " " << retrieveValue(now / 2) << " " << comp[now] <<"\n";        
        if (now % 2 == 0) {
            if (toi > 0 && !st.count(toi)) {
                ans.push_back(arg);
                st.insert(toi);
            }
        }          
    }
    
    return ans;
}

int main(void) {
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
            R[i].clear();
        }


        for (int i = 0; i < N; i++) {
            //addNot(realValue(to_string(i) + "h"), realValue(to_string(i) + "w"));
        }
        
        for (int i = 0; i < M; i++) {
            string a, b;
            cin >> a >> b;

            int va = realValue(a);
            int vb = realValue(b);

            //cout << a << " " << va << "\n";
            //cout << b << " " << vb << "\n";

            addNot(va, vb);
            
            //R[va].push_back(vb ^ 1);
            //G[vb ^ 1].push_back(va);
            
            //R[vb].push_back(va ^ 1);
            //G[va ^ 1].push_back(vb);                
        }

        if (!twoSat()) {
            cout << "bad luck\n";
        } else {
            vector<string> ans = retrievePath();

            sort(ans.begin(), ans.end());
            
            for (int i = 0; i < (int) ans.size(); i++) {
                if (i > 0) {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
