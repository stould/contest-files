#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAXN = 100010;

char c;

int i, k, n, x, y;

int g[MAXN], p[MAXN];

int find( int a ){
	if( g[a]==a ){
		return a;
	}
	return g[a]=find(g[a]);
}

void join( int a, int b ){
	int g1 = find(a);
	int g2 = find(b);
	if( g1!=g2 ){
		if( p[g1]>p[g2] ){
			g[g2]=g1;
		}
		else{
			g[g1]=g2;
			if( p[g1]==p[g2] ){
				p[g2]++;
			}
		}
	}
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> n >> k;

    for(i = 0; i < k; i++) {
        cin >> c >> x >> y;
        if(c == 'F') {
            join(x, y);
        } else {
            int a = find(x);
            int b = find(y);

            cout << a << " " << b << endl;
        }
    }
    return 0;
}
