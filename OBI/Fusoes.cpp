#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

char c;
int a, b, i, j, n, k;

int main(void) {
    cin >> n >> k;
    vector<pair<int, int> > mem;

    for(i = 0; i < k; i++) {
        cin >> c >> a >> b;
        if(c == 'F') {
            mem.push_back(make_pair(a, b));
        } else {
            bool ok = false;
            queue<int> q;
            vector<bool> vis(n + 1, false);
            q.push(b);

            while(!q.empty()) {
                int tmp = q.front();
                q.pop();

                vis[tmp] = true;

                if(tmp == a) {
                    ok = true;
                    break;
                }
                for(j = 0; j < (int) mem.size(); j++) {
                    if(mem[j].first == tmp && !vis[mem[j].second]) {
                        q.push(mem[j].second);
                    }
                    if(mem[j].second == tmp && !vis[mem[j].first]) {
                        q.push(mem[j].first);
                    }
                }
            }
            if(ok) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}
