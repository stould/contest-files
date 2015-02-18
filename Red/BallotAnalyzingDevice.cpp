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

int N, M;
string S[120], B[1010];
int cnt[120];

struct data {
	int id, votes;
	string name;

	data(){}

	data(int id, string name, int votes):
		id(id),
		name(name),
		votes(votes){}

	bool operator<(const data& other) const {
		if (votes != other.votes) {
			return votes > other.votes;
		} else {
			return id < other.id;
		}
	}
};

int fix(int value, int total) {
	int a = value * 10000;	
	return (a / total) + ((2 * (a % total)) >= total);
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	
	int invalid = 0;

	for (int i = 0; i < M; i++) {
		cin >> B[i];

		if (count(B[i].begin(), B[i].end(), 'X') != 1) {
			invalid += 1;
		} else {
			for (int j = 0; j < N; j++) {
				if (B[i][j] == 'X') {
					cnt[j] += 1;
					break;
				}
			}
		}
	}

	vector<data> vs;

	for (int i = 0; i < N; i++) {
		vs.push_back(data(i, S[i], cnt[i]));
	}

	sort(vs.begin(), vs.end());
	
	for (int i = 0; i < N; i++) {
		int p = fix(vs[i].votes, M);
		printf("%s %d.%d%d%%\n", vs[i].name.c_str(), p / 100, (p / 10) % 10, p % 10);
	}

	int p = fix(invalid, M);
	printf("%s %d.%d%d%%\n", "Invalid", p / 100, (p / 10) % 10, p % 10);

	return 0;
}
