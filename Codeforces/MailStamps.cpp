#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n;
map<ll, vector<ll> > mem;
map<ll, vector<ll> >::iterator it;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        mem[a].push_back(b);
        mem[b].push_back(a);
    }

    ll start = -1;
    for(it = mem.begin(); it != mem.end(); it++) {
        if(it->second.size() == 1) { start = it->first; break; }
    }
    cout << start;

	ll pre = start;
	start = mem[start][0];

	while (true) {
	    cout << " " << start;
		if (mem[start].size() == 1) {
			break;
		}
		if (mem[start][0] == pre) {
			pre = start;
			start = mem[start][1];
		} else {
			pre = start;
			start = mem[start][0];
		}
	}
	cout << endl;
    return 0;
}
