#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

const int MX = 100001;
const int INF = 1000001;

int n, m, dist[MX], prev[MX];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] < dist[y];
    }
};

int main(void) {
    cin >> n >> m;
    vector<pair<int, int> > p[n + 1];
    for(int i = 1; i <= n; i++) { dist[i] = INF; prev[i] = -1; }
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        p[a].push_back(make_pair(b, c));
        p[b].push_back(make_pair(a, c));
    }

    dist[1] = 0;

    priority_queue<int, vector<int>, MyLess> pq;

    pq.push(1);

    while(!pq.empty()) {
        int tmp = pq.top(); pq.pop();

        for(int i = 0; i < p[tmp].size(); i++) {
            int ac_cost = dist[p[tmp][i].first];
            int no_cost = dist[tmp] + p[tmp][i].second;

            if(no_cost < ac_cost) {
                dist[p[tmp][i].first] = dist[tmp] + p[tmp][i].second;
                prev[p[tmp][i].first] = tmp;
                pq.push(p[tmp][i].first);
            }
        }
    }

    if(dist[n] == MX) {
        cout << "-1" << endl;
    } else {
        vector<int> ans;
        int end = n;
        ans.push_back(end);
        while(prev[end] != -1) {
            ans.push_back(prev[end]);
            end = prev[end];
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            if(i == ans.size() - 1) {
                cout << ans[i] << endl;
            } else {
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}
