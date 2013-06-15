#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a, n, p;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n >> p && !(n == 0 && p == 0)) {
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++) {
            cin >> a;
            q.push(make_pair(i, a));
        }
        int trocas = 0, atual = 0;
        while(1) {
            int x = q.top(); q.pop(); atual++;
            if(atual > p) {
                atual =
            }
        }
        cout << trocas << endl;
    }
    return 0;
}
