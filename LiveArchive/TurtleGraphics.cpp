#include <bits/stdc++.h>

using namespace std;

int T;
int SI, SJ;
string P;
map<char, int> dx, dy;

char rot_right(char x) {
	if (x == 'N') {
		return 'E';
	} else if (x == 'E') {
		return 'S';
	} else if (x == 'S') {
		return 'O';
	} else {
		return 'N';
	}
}

char rot_left(char x) {
	if (x == 'N') {
		return 'O';
	} else if (x == 'O') {
		return 'S';
	} else if (x == 'S') {
		return 'E';
	} else {
		return 'N';
	}
}

int main() {
	cin >> T;

	dx['S'] = -1; dy['S'] = 0;
	dx['N'] = +1; dy['N'] = 0;
	dx['E'] = 0;  dy['E'] = +1;
	dx['O'] = 0;  dy['O'] = -1;

	for (int t = 1; t <= T; t++) {
		cin >> SJ >> SI >> P;

		char dir = 'N';

		map<pair<int, int>, int> vis;
		vis[make_pair(SI, SJ)] += 1;
		int seen = 0;

		for (int i = 0; i < (int) P.size(); i++) { 
			if (P[i] == 'F') {
				SI = SI + dx[dir];
				SJ = SJ + dy[dir]; 

				vis[make_pair(SI, SJ)] += 1;
			} else {
				if (P[i] == 'R') {
					dir = rot_right(dir);
				} else {
					dir = rot_left(dir);
				}
			}
		}

		map<pair<int, int>, int>::iterator it;
		for (it = vis.begin(); it != vis.end(); it++) {
			if (it->second > 1) {
				seen += 1;
			}
		}
		cout << "Case #" << t << ": " << SJ << " " << SI << " " << seen << "\n";
	}
	return 0;
}
