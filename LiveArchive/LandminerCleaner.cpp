#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T, N, M;
int P[MAXN][MAXN], rest[MAXN][MAXN];
char ans[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

bool cmp(pair<int, int> a, pair<int, int> b) {
    return rest[a.first][a.second] > rest[b.first][b.second];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        queue<pair<int, pair<int, int> > > st;
        vector<pair<int, int> > buffer;
        int best = 4;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
                rest[i][j] = P[i][j];
                vis[i][j] = false;

                if (best == P[i][j]) {
                    buffer.push_back(make_pair(i, j));
                } else if  (best < P[i][j]) {
                    best = P[i][j];
                    buffer.clear();
                    buffer.push_back(make_pair(i, j));
                }	
                ans[i][j] = '-';
            }
        }

        for (int i = 0; i < (int) buffer.size(); i++) {
            int pi = buffer[i].first;
            int pj = buffer[i].second;
      
            st.push(make_pair(P[pi][pj], make_pair(pi, pj)));
        }

        while (!st.empty()) {
            pair<int, pair<int, int> > curr = st.front();
            st.pop();

            int pi = curr.second.first;
            int pj = curr.second.second;

            if (rest[pi][pj] <= 0) continue;

            ans[pi][pj] = 'L';

            if (!vis[pi][pj]) {
                rest[pi][pj] -= 4;
            }
      
            vector<pair<int, int> > pq;

            for (int j = 0; j < 8; j++) {
                int qi = pi + dx[j];
                int qj = pj + dy[j];

                if (qi >= 0 && qj >= 0 && qi < N && qj < M) {
                    pq.push_back(make_pair(qi, qj));
                }
            }

            sort(pq.begin(), pq.end(), cmp);

            for (int j = 0; j < (int) pq.size(); j++) {
                int oi = pq[j].first;
                int oj = pq[j].second;

                if (j < P[pi][pj] - 4) {		  
                    if (P[oi][oj] >= 4 && rest[oi][oj] > 0 && !vis[oi][oj]) {    
                        st.push(make_pair(rest[oi][oj], make_pair(oi, oj)));
                        vis[oi][oj] = true;
                    }
                }
                if (rest[oi][oj] > 0) {
                    rest[oi][oj] -= 1;
                }	  	
            }      
            rest[pi][pj] = 0;
            /*
              for (int j = 0; j < N; j++) {
              for (int k = 0; k < M; k++) {
              cout << rest[j][k] << " ";
              }
              cout << "\n";
              }
              cout << "\n";
            */
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
