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

class TrainingCamp {
public:
	vector <string> determineSolvers(vector <string>, vector <string>);
};

vector <string> TrainingCamp::determineSolvers(vector <string> attendance, vector <string> problemTopics) {
	int N = (int) attendance.size();
	int M = (int) attendance[0].size();
	int K = (int) problemTopics.size();
	
	
	vector<string> ans(N, string(K, 'X'));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			bool ok = true;
			for (int k = 0; k < M; k++) {
				if (attendance[i][k] == '-' && problemTopics[j][k] == 'X') {
					ok = false;
				}
			}
			if (!ok) {
				ans[i][j] = '-';				
			}
		}
	}
	
	return ans;	
}

//Powered by [KawigiEdit] 2.0!
