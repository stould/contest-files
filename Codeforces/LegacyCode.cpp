#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;

int N;
string NM[MAXN];
int C[MAXN];
vector<int> G[MAXN];
map<string, int> conv;
int id = 1;
int vis[MAXN];

int fix(string arg) {
    if (conv[arg] == 0) {
        conv[arg] = id++;
    }
    return conv[arg];
}

int dfs(int x) {
    vis[x] = true;

    int ans = 1;

    for (int i = 0; i < G[x].size(); i++) {
        int next = G[x][i];

        if (!vis[next]) {
            ans += dfs(next);
        }
    }

    return ans;
}

bool isBase(string arg) {
    string other = "";
    bool fine = false;

    for (int i = 0; i < (int) arg.size(); i++) {
        if (fine) {
            other += arg[i];
        }
        if (i > 1 && arg[i - 1] == ':' && arg[i] == ':') {
            fine = true;
        }
    }
    return other == "PROGRAM";
}

int main() {
    cin >> N;

    vector<int> base;
  
    for (int i = 0; i < N; i++) {
        cin >> NM[i] >> C[i];

        fix(NM[i]);

        if (isBase(NM[i])) {
            base.push_back(fix(NM[i]));
        }

        string F;
    
        for (int j = 0; j < C[i]; j++) {
            cin >> F;

            G[fix(F)].push_back(fix(NM[i]));
        }
    }

    int ans = 0;
  
    for (int i = 0; i < (int) base.size(); i++) {
        dfs(base[i]);
    }
  
    for (int i = 1; i < id; i++) {
        if (!vis[i]) {
            ans += 1;
        }
    }
  
    cout << ans << "\n";
 
    return 0;
}
