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

class Suminator {
public:
	int findMissing(vector <int>, int);
};

Int simul(vector<Int> vs) {
	stack<Int> s;
	
	for (int i = 0; i < (int) vs.size(); i++) {
		if (vs[i] == 0) {
			Int pa = 0;
			Int pb = 0;
			
			if (!s.empty()) {
				pa = s.top(); 
				s.pop();
			}
			if (!s.empty()) {
				pb = s.top(); 
				s.pop();
			}
			
			s.push(pa + pb);
		} else {
			s.push(vs[i]);
		}
	}
	
	return s.top();
}

int Suminator::findMissing(vector <int> _program, int wantedResult) {
	int pos = -1;
	int N = _program.size();
	
	vector<Int> program;
	
	for (int i = 0; i < N; i++) {
		program.push_back((Int) _program[i]);
	}
	
	for (int i = 0; i < N; i++) {
		if (program[i] == -1) {
			pos = i;
		}
	}
	
	program[pos] = 0;
	
	if (simul(program) == wantedResult) {
		return 0;
	} else {
		Int l = 0, h = 100000000100LL, m;
		Int best = LLONG_MAX;
		
		while (l <= h) {
			m = l + (h - l) / 2;
			
			program[pos] = m;
						
			Int curr = simul(program);
			
			if (curr == wantedResult) {
				best = min(best, m);
				h = m - 1;
			} else if (curr < wantedResult) {
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		if (best == LLONG_MAX) {
			return -1;
		} else {
			return (int) best;
		}
	}	
}	

//Powered by [KawigiEdit] 2.0!
