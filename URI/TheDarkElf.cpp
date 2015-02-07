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

const double EPS = 1e-7;

int T, N, M;

struct data {
	string name;
	int weight, age;
	double height;

	bool operator<(const data& other) const {
		if (weight != other.weight) {
			return weight < other.weight;
		} else {
			if (age != other.age) {
				return age > other.age;
			} else {
				if (fabs(height - other.height) > EPS) {
					return height > other.height;
				} else {
					return name < other.name;
				}
			}
		}
	}
};

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		vector<data> vd(N);
		
		for (int i = 0; i < N; i++) {
			cin >> vd[i].name >> vd[i].weight >> vd[i].age >> vd[i].height;
		}

		sort(vd.rbegin(), vd.rend());

		cout << "CENARIO {" << t << "}\n";
		
		for (int i = 0; i < M; i++) {
			cout << i + 1 << " - " << vd[i].name << "\n";
		}
	}
	
    return 0;
}
