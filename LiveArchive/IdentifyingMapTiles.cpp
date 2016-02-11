#include <bits/stdc++.h>

using namespace std;

string S;
map<char, int> dx;
map<char, int> dy;

int main() {
	cin >> S;

	dx['0'] = 0;
	dy['0'] = 0;

	dx['1'] = 1;
	dy['1'] = 0;

	dx['2'] = 0;
	dy['2'] = 1;

	dx['3'] = 1;
	dy['3'] = 1;
  
	int N = (int) S.size();

	int x = 0, y = 0;
	int level = 1;

	for (int i = N - 1; i >= 0; i--) {
		x += level * dx[S[i]];
		y += level * dy[S[i]];
    
		level *= 2;
	}

	cout << N << " " << x << " " << y << "\n";
  
	return 0;
}
