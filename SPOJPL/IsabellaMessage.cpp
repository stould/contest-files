#include <iostream>
#include <vector>
#include <map>

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

const int MAXN = 53;

int T, N, M;
string S[110];
string tab[MAXN], mat[5][MAXN];
map<string, int> words;

vector<string> func(int start_pos) {
	vector<string> ans;

	string dict = "";
	string buff = "";

	int seen = 0;

	for (int pos = 0; pos < 4; pos++) {
		int curr_pos = (start_pos + pos) % 4;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (seen < N * N && mat[curr_pos][i][j] == '*') {
					if (tab[i][j] != '.' || (dict.size() > 0 && dict[dict.size() - 1] != '.')) {
						dict += tab[i][j];
					}
					seen += 1;					
				}
			}
		}		
		if (seen >= N * N) break;
	}

	vector<string> word_buff;

	for (int i = 0; i < (int) dict.size(); i++) {
		if (dict[i] == '.') {
			word_buff.push_back(buff);
			buff = "";
		} else {
			buff += dict[i];
		}
	}

	if (buff != "") {
		word_buff.push_back(buff);
		buff = "";
	}

	bool valid = true;

	for (int i = 0; i < (int) word_buff.size(); i++) {
		if (words[word_buff[i]] == 0) {
			valid = false;
		}
		ans.push_back(word_buff[i]);
	}

	if (!valid) {
		ans.clear();
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		words.clear();

		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> tab[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> mat[0][i];

			for (int pos = 1; pos < 4; pos++) {
				mat[pos][i] = mat[0][i];
			}
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> S[i];
			words[S[i]] += 1;
		}

		//generate rotated matrices
		for (int pos = 1; pos < 4; pos++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					mat[pos][j][N - i - 1] = mat[pos - 1][i][j];
				}
			}
		}
		
		vector<string> ans;
		
		for (int i = 0; i < 4; i++) {
			vector<string> vbuff = func(i);
			
			if (!vbuff.empty()) {
				if (ans.empty()) {
					ans = vbuff;
				} else {
					if (vbuff < ans) {
						ans = vbuff;
					}
				}
			}
		}
				
		cout << "Case #" << t << ": ";

		if (ans.empty()) {
			cout << "FAIL TO DECRYPT\n";
		} else {
			for (int i = 0; i < (int) ans.size(); i++) {
				if (i > 0) {
					cout << " ";
				}
				cout << ans[i];
			}
			cout << "\n";
		}
	}
    return 0;
}
