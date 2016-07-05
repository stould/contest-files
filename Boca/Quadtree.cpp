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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 520;

int N;
int P[MAXN][MAXN];
vector<string> ans;


int kind(int li, int lj, int len) {
	int z = 0, o = 0;
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (P[li + i][lj + j] == 0) {
				z += 1;
			} else {
				o += 1;
			}
		}
	}
	
	if (z > 0 && o > 0) {
		return 2;
	} else {
		if (z > 0) {
			return 0;
		} else {
			return 1;
		}
	}
}

struct state {
	int li, lj, len;
	
};

void func(int _li, int _lj, int _len) {
	queue<state> q;
	q.push({_li, _lj, _len});

	while (!q.empty()) {
		int li = q.front().li;
		int lj = q.front().lj;
		int len = q.front().len;
		q.pop();
		
		string curr = "";

		curr += char('0' + kind(li, lj, len / 2));
		curr += char('0' + kind(li, lj + len / 2, len / 2));
		curr += char('0' + kind(li + len / 2, lj + len / 2, len / 2));
		curr += char('0' + kind(li + len / 2, lj, len / 2));

		ans.push_back(curr);
		
		if (curr[0] == '2') {
			q.push({li, lj, len / 2});
			//func(li, lj, len / 2, level + 1, 0);
		}
		if (curr[1] == '2') {
			q.push({li, lj + len / 2, len / 2});
			//func(li, lj + len / 2, len / 2, level + 1, 1);
		}
		if (curr[2] == '2') {
			q.push({li + len / 2, lj + len / 2, len / 2});
			//func(li + len / 2, lj + len / 2, len / 2, level + 1, 2);
		}
		if (curr[3] == '2') {
			q.push({li + len / 2, lj, len / 2});
			//func(li + len / 2, lj, len / 2, level + 1, 3);
		}
	}
}

int main(void) {
	while (cin >> N && N != 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> P[i][j];
			}
		}
		
		cout << N << " " << kind(0, 0, N) << "\n";
		
		ans.clear();

		if (kind(0, 0, N) == 2) {
			func(0, 0, N);
		}

		//sort(ans.begin(), ans.end());
		
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		cout << "\n";
	}	
	return 0;
}
