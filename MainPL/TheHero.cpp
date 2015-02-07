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

int N;
Int Z;


struct data {
	int id;
	Int d, a;

	data(){}

	data(int id, int d, int a): id(id), d(d), a(a) {}
};

bool profit_logic(data a, data b) {
	return (a.d != b.d) ? (a.d < b.d) : (a.a > b.a);
}

bool damage_logic(data a, data b) {
	return (a.a != b.a) ? (a.a > b.a) : (a.d > b.d);
}

int main(void) {
	while (cin >> N >> Z) {
		int D, A;
		
		vector<data> profit, damage;
		vector<int> ans;
		
		bool ok = true;
		
		for (int i = 0; i < N; i++) {
			cin >> D >> A;
			
			if (D <= A) {
				profit.push_back(data(i + 1, D, A));
			} else {
				damage.push_back(data(i + 1, D, A));
			}
		}

		if (profit.empty()) {
			ok = false;
		}
		
		sort(profit.begin(), profit.end(), profit_logic);
	   
		
		for (int i = 0; i < (int) profit.size(); i++) {
			ans.push_back(profit[i].id);
			
			Z -= profit[i].d;
			Z += profit[i].a;
		}
		
		sort(damage.begin(), damage.end(), damage_logic);
		
		for (int i = 0; i < (int) damage.size(); i++) {
			ans.push_back(damage[i].id);
			
			Z -= damage[i].d;

			if (Z <= 0) {
				ok = false;
			} else {
				Z += damage[i].a;
			}
		}
		
		if (!ok) {
			cout << "NIE\n";
		} else {
			cout << "TAK\n";
			
			for (int i = 0; i < N; i++) {
				cout << ans[i] << " ";
			}
			
			cout << "\n";
		}
	}
	
    return 0;
}
