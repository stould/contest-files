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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 220;

int N, M;
string A[MAXN], B[MAXN];
vector<int> G[MAXN];
int dp[MAXN][MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) G[u].size(); i++) {
		int v = G[u][i];

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
    int matchR[MAXN];
 
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

bool can(string& P, string& Q) {
	int PL = (int) P.size();
	int QL = (int) Q.size();

	vector<int> VP(PL, 0), seenP(30, 0);
	vector<int> VQ(QL, 0), seenQ(30, 0);

	for (int i = 0; i < PL; i++) {
		int index = P[i] - 'A' + 1;
		VP[i] = index + 26 * seenP[index];
		//cout << VP[i] << " ";
		seenP[index] += 1;
	}
	//cout << "\n";	
	for (int i = 0; i < QL; i++) {
		int index = Q[i] - 'A' + 1;
		VQ[i] = index + 26 * seenQ[index];
		//cout << VQ[i] << " ";
		seenQ[index] += 1;
	}
	//cout << "\n";
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1; i <= PL; i++) {
		for(int j = 1; j <= QL; j++) {
			if(VP[i - 1] == VQ[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	if ((PL + QL - 2 * dp[PL][QL]) % 5 == 0) {
		//cout << P << " " << Q << " " << dp[PL][QL] << " " << PL + QL - 2 * dp[PL][QL] << "\n";
	}
	return (PL + QL - 2 * dp[PL][QL]) % 5 == 0;
}

int main(void) {
	while (cin >> N >> M) {
		if (N == 0 && M == 0) {
			break;
		}
		
		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
		}
		
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (can(A[i], B[j])) {
					G[i].push_back(N + j);
				}
			}
		}

		int ans = maxBPM();
		//cout << ans << "\n";
		cout << fixed << setprecision(2) << "P = " << ans * 100.0 / (double) N << "\n";
	}
	return 0;
}
