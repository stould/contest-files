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

int T, N, M;

struct team {
	string name;
	int point, goal;
	int id, win, draw, lose;

	bool operator<(const team& other) const {
		if (point != other.point) {
			return point > other.point;
		} else {
			if (win != other.win) {
				return win > other.win;
			} else {
				if (goal != other.goal) {
					return goal > other.goal;
				} else {
					return id < other.id;
				}
			}
		}
	}
};

int main(void) {
	cin >> T;
	
	for ( ; T--; ) {
		cin >> N >> M;
		
		vector<team> vt;
		string S, S1, S2;
		int V1, V2;

		map<string, int> pi;

		for (int i = 0; i < N; i++) {
			cin >> S;

			pi[S] = i;
			
			team ts;
			ts.name = S;
			ts.id = i;
			ts.point = ts.win = ts.draw = ts.lose = ts.goal = 0;

			vt.push_back(ts);
		}	   
		
		for (int i = 0; i < M; i++) {
			cin >> V1 >> S1 >> V2 >> S2;

			vt[pi[S1]].goal += V1;
			vt[pi[S2]].goal += V2;

			if (V1 == V2) {
				vt[pi[S1]].point += 1;
				vt[pi[S2]].point += 1;
				vt[pi[S1]].draw += 1;
				vt[pi[S2]].draw += 1;
			} else {
				if (V1 > V2) {
					vt[pi[S1]].point += 3;
					vt[pi[S1]].win += 1;
					vt[pi[S2]].lose += 1;
				} else {
					vt[pi[S2]].point += 3;
					vt[pi[S1]].lose += 1;
					vt[pi[S2]].win += 1;
				}
			}
		}
		sort(vt.begin(), vt.end());
		
		for (int i = 0; i < N; i++) {
			cout << vt[i].name << "\n";
		}
	}
    return 0;
}
