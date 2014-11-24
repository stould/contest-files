#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int TL[10];
char S[110];

int map_key[10];
string key[10];

int main(void) {
	key[1] = "";
	key[2] = "abc";
	key[3] = "def";
	key[4] = "ghi";
	key[5] = "jkl";
	key[6] = "mno";
	key[7] = "pqrs";
	key[8] = "tuv";
	key[9] = "wxyz";

	for (int i = 1; i <= 9; i++) {
		scanf("%d", &TL[i]);
		map_key[i] = TL[i];
	}

	scanf("%s", S);

	int N = strlen(S);
	int last = -1;

	for (int i = 0; i < N; i++) {
		int id = -1, press = 0;
		bool sharp = false;

		for (int j = 1; j <= 9; j++) {
			if (key[map_key[j]].find(S[i]) != string::npos) {
				//cout << "\n" << j << " " << S[i] << " " << key[map_key[j]] << "\n";
				id = j;
				for (int k = 0; k < key[map_key[j]].size(); k++) {
					if (key[map_key[j]][k] == S[i]) {
						press = k;
						break;
					}
				}
				if (i > 0) {
					if (id == last) {
						sharp = true;
					}
				}
				last = j;
				break;
			}
		}
		if (sharp) {
			putchar('#');
		}
		for (int i = 0; i <= press; i++) {
			printf("%d", id);
		}
	}
	printf("\n");
    return 0;
}
