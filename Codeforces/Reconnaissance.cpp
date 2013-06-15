#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    vector<int> soldiers(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &soldiers[i]);
    }

    set<pair<int, int> > s;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && abs(soldiers[i] - soldiers[j]) <= d) {
                s.insert(make_pair(i, j));
            }
        }
    }

    cout << s.size() << endl;

    return 0;
}
