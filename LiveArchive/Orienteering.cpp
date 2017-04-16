#include <bits/stdc++.h>

using namespace std;

const double INF = 10010010011010.0;
const int MAXN = 45;
const int MAX_PROFIT = 200 * 32;

int N;
string S;
int D;
pair<int, int> P[MAXN];
int SC[MAXN];
double dist[MAXN][MAX_PROFIT];

int can(int max_spent, int gain) {
    priority_queue<pair<pair<double, int>, int> > q;
    q.push(make_pair(make_pair(0.0, 0), 0));
  
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAX_PROFIT; j++) {
            dist[i][j] = INF;
        }
    }
  
    dist[0][0] = 0;

    while (!q.empty()) {
        double len = -q.top().first.first;
        int pro = +q.top().first.second;
        int pos = q.top().second;
        q.pop();
    
        if (len + hypot(P[pos].first, P[pos].second) > max_spent) {
            continue;
        }
      
        if (pro >= gain) {
            return 1;
        }
      
        for (int i = pos + 1; i <= N; i++) {
            double next_len = len + hypot(P[pos].first - P[i].first, P[pos].second - P[i].second);
            int next_pro = pro + SC[i];
            int next = i;

            if (dist[next][next_pro] > dist[pos][pro] + next_len) {
                dist[next][next_pro] = dist[pos][pro] + next_len;
                q.push(make_pair(make_pair(-next_len, next_pro), next));
            }
        }
    }
  
    return 0;
}

int main() {
    int test = 1;

    while (cin >> N && N != 0) {
        cout << "Race " << test++ << "\n";
    
        P[0].first = 0;
        P[0].second = 0;
    
        for (int i = 1; i <= N; i++) {
            cin >> P[i].first >> P[i].second >> SC[i];
        }

        while (cin >> S >> D) {
            if (S == "#") break;
      
            int l = 0, h = MAX_PROFIT, m;
            int best = 0;

            while (l <= h) {
                m = (l + h) / 2;

                if (can(D, m)) {
                    best = m;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
      
            cout << S << ": " << best << "\n";
        }
    }
    return 0;
}
