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

class PrimePairs {
public:
	vector <int> matches(vector <int>);
};

const int MAXN = 70;

int N;
vector<int> graph[MAXN];
int matchR[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
		int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM() { 
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 0; u < MAXN; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            result++;
		}
    }

    return result;
}

void clear() {
	for (int i = 0; i < MAXN; i++) {
		graph[i].clear();
	}
}

bool isPrime(int x) {
	if (x <= 1) {
		return false;
	} else if (x == 2 or x == 3) {
		return true;
	} else if (x % 2 == 0) {
		return false;
	} else {
		for (int i = 3; i <= (int) sqrt(x); i += 2) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}

vector <int> PrimePairs::matches(vector <int> numbers) {
	N = (int) numbers.size();
	vector<int> ans;
	
	for (int i = 1; i < N; i++) {
		if (isPrime(numbers[0] + numbers[i])) {
			clear();
			
			if (numbers[0] % 2 == 0) {
				graph[0].push_back(i);
			} else {
				graph[i].push_back(0);
			}
			
			for (int j = 1; j < N; j++) {
				if (i != j && numbers[j] % 2 == 0) {
					for (int k = 1; k < N; k++) {
						if (i != k && numbers[k] % 2 == 1) {	
							if (isPrime(numbers[j] + numbers[k])) {
								graph[j].push_back(k);
							}
						}
					}			
				}
			}
			int check = maxBPM();
			
			if (check == N / 2) {
				ans.push_back(numbers[i]);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
