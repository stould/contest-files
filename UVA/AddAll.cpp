#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,tmp;

int main(void) {
    while(cin >> n && n != 0) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < n; i++) { cin >> tmp; q.push(tmp); }
        int cost = 0;
        for(; q.size() >= 2; ) {
            int tmp = q.top(); q.pop(); tmp += q.top(); q.pop();
            cost += tmp;
            q.push(tmp);
        }
        cout << cost << endl;
    }
    return 0;
}
