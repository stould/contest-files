#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

struct Player {
    int index, value;

    Player() {}
    Player(int _i, int _v) {
        index = _i;
        value = _v;
    }
    bool operator<(const Player& p) const {
        return value < p.value;
    }
};

int n;

int main(void) {
    scanf("%d", &n);
    vector<Player> pp(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &pp[i].value);
        pp[i].index = i + 1;
    }
    sort(pp.begin(), pp.end());
    vector<Player> ta, tb;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            ta.push_back(pp[i]);
        } else {
            tb.push_back(pp[i]);
        }
    }
    printf("%d\n", ta.size());
    for(int i = 0; i < ta.size(); i++) {
        if(i != ta.size() - 1) {
            printf("%d ", ta[i].index);
        } else {
            printf("%d\n", ta[i].index);
        }
    }
    printf("%d\n", tb.size());
    for(int i = 0; i < tb.size(); i++) {
        if(i != tb.size() - 1) {
            printf("%d ", tb[i].index);
        } else {
            printf("%d\n", tb[i].index);
        }
    }
    return 0;
}

