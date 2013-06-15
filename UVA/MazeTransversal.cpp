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
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int dx[4] = {1, -1,  0, 0};
const int dy[4] = {0,  0, -1, 1};

int d, i, j, t, n, m, x, y;
string com, maze[70];
char c, ac, str[300];

void right() {
	switch(ac) {
		case 'N': ac = 'E'; break;
		case 'E': ac = 'S'; break;
		case 'S': ac = 'W'; break;
		case 'W': ac = 'N'; break;
	}
}

void left() {
	switch(ac) {
		case 'N': ac = 'W'; break;
		case 'W': ac = 'S'; break;
		case 'S': ac = 'E'; break;
		case 'E': ac = 'N'; break;
	}
}

void forward(){
	if (ac == 'E'){
		if (maze[x][y+1] != '*')
			++y;
	}
	else if (ac == 'W'){
		if (maze[x][y-1] != '*')
			--y;
	}
	else if (ac == 'S'){
		if (maze[x+1][y] != '*')
			++x;
	}
	else if (ac == 'N'){
		if (maze[x-1][y] != '*')
			--x;
	}
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> t; bool flag = true;
    while(t--) {
        cin >> n >> m; cin.getline(str, sizeof(str));
        REP(i, n) {
            cin.getline(str, sizeof(str));
			maze[i] = str;
        }
        cin >> x >> y;
        ac = 'N';
        x -= 1; y -= 1;
        while ( (c = cin.get()) != 'Q'){
            if(c == 'F') {
                forward();
                            cout << x << " " << y << " " << ac << endl;

            } else if(c == 'R') {
                right();
            } else {
                left();
            }
        }
        if(flag) cout << endl; flag = false;
        cout << (x + 1) << " " << (y + 1) << " " << ac << endl;
    }
    return 0;
}
