#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const double EPS = 1e-5;

int T, N;
long long X[MAXN], Y[MAXN], R[MAXN];
vector<int> G[MAXN];
int sent[MAXN];
int n[MAXN], d[MAXN];
int vis[MAXN];

bool reach(int i, int j) {
    long long ds = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
    //cout << i << " " << j << " " << ds << " " << (R[i] + R[j]) * (R[i] + R[j])<< "\n";
    return ds == (R[i] + R[j]) * (R[i] + R[j]);
}

void dfs(int x) {
    vis[x] = 1;

    for (auto& it : G[x]) {
        if (!vis[it]) {
            n[it] = R[0];
            d[it] = R[it];
            //cout << it << " "<< n[it] << " " << d[it] << "\n";
            int gc = __gcd(n[it], d[it]);

            n[it] /= gc;
            d[it] /= gc;

            sent[it] = sent[x] ^ 1;

            dfs(it);
        }
    }
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            G[i].clear();
            sent[i] = 1;
            vis[i] = 0;
        }
        
        n[0] = 1;
        d[0] = 1;
        
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i] >> R[i];
            
            for (int j = 0; j < i; j++) {
                if (reach(i, j)) {
                    //cout << j << " " << i << "\n";
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        dfs(0);

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                cout << "not moving\n";
            } else {
                if (d[i] == 1) {
                    cout << n[i] << " ";
                } else {
                    cout << n[i] << "/" << d[i] << " ";
                }
                if (sent[i]) {
                    cout << "clockwise\n";
                } else {
                    cout << "counterclockwise\n";
                }
            }
        }
    }
    return 0;
}

