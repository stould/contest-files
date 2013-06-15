#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int c, l, a, b, s, e, d, state[210][210];
vector<int> graph[110];

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> c >> l && !(c == 0 && l == 0)) {
        for(int i = 0; i < 110; i++) graph[i].clear();
        for(int i = 0; i < l; i++) {
            cin >> a >> b; a -= 1; b -= 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cin >> s >> e >> d; s -= 1; e -= 1;
        queue<pair<int, int> > q; q.push(make_pair(s, 0));
        memset(state, 0, sizeof(state));
        while(!q.empty()) {
            int index = q.front().first;
            int days = q.front().second;
            q.pop();
            for(int i = 0; i < graph[index].size(); i++) if(!state[graph[index][i]][days + 1] && days + 1 <= d) {
                q.push(make_pair(graph[index][i], days + 1));
                state[graph[index][i]][days + 1] = 1;
            }
        }
        end:;
        if(state[e][d] || (d == 0 && s == e)) {
            cout << "Yes, Teobaldo can travel.\n";
        } else {
            cout << "No, Teobaldo can not travel.\n";
        }
    }
    return 0;
}
