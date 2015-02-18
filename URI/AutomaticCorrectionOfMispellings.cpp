#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <climits>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N, Q;
string S;

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		set<string> buff;
		map<string, int> id;

		for (int i = 0; i < N; i++) {
			cin >> S;
			buff.insert(S);
			id[S] = i;
		}

		cin >> Q;

		for (int i = 0; i < Q; i++) {
			cin >> S;

			if (buff.count(S)) {
				cout << S << " is correct\n";
			} else {
				int curr_id = INT_MAX;
				string ans = "";

				for (int i = 0; i < S.size(); i++) {
					if (i + 1 < S.size()) {
						string sw = S;
						swap(sw[i], sw[i + 1]);
						
						if (buff.count(sw) && id[sw] < curr_id) {
							curr_id = id[sw];
							ans = sw;
						}
					}

					string er = S.substr(0, i) + S.substr(i + 1, S.size() - i + 1);

					if (buff.count(er) && id[er] < curr_id) {
						curr_id = id[er];
						ans = er;
					}

					for (char c = 'a'; c <= 'z'; c++) {
						string ch = S;
						ch[i] = c;
						
						if (buff.count(ch) && id[ch] < curr_id) {
							curr_id = id[ch];
							ans = ch;
						}	

						string is = S.substr(0, i) + c + S.substr(i, S.size() - i + 1);

						if (buff.count(is) && id[is] < curr_id) {
							curr_id = id[is];
							ans = is;
						}	
					}
					for (char c = 'a'; c <= 'z'; c++) {
						string is = S + c;
						
						if (buff.count(is) && id[is] < curr_id) {
							curr_id = id[is];
							ans = is;
						}	
					}												
				}
				if (curr_id == INT_MAX) {
					cout << S << " is unknown\n";
				} else {
					cout << S << " is a misspelling of " << ans << "\n";
				}
			}
		}
	}
    return 0;
}
