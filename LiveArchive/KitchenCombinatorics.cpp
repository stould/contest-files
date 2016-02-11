#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const double EPS = 1e-8;

int R, S, M, D, N;
int BR[1010];
int IN[1010];
int C[1010][1010];
int NOT[1010][1010];

int highestOneBitPosition(ull a) {
	int bits=0;
	while (a > 0) {
		++bits;
		a>>=1LL;
	}
	return bits;
}

bool addition_is_safe(ull a, ull b) {
	int a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
	return (a_bits<62 && b_bits<62);
}

bool multiplication_is_safe(ull a, ull b) {
	int a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
	return (a_bits+b_bits<=62);
}

int main() {
	cin >> R >> S >> M >> D >> N;
	for (int i = 0; i < R; i++) {
		cin >> BR[i];
	}

	for (int i = 0; i < S + M + D;i++) {
		cin >> IN[i];

		for (int j = 0; j < IN[i]; j++) {
			cin >> C[i][j];

			C[i][j] -= 1;
		}
	}

	for (int i = 0; i < N; i++) {
		int P, Q;
		cin >> P >> Q;

		P -= 1;
		Q -= 1;
    
		NOT[P][Q] = NOT[Q][P] = 1;
	}

	unsigned long long ans = 0;
	long long lg = 0;
  
	bool can = true;
  
	for (int i = 0; i < S && can; i++) {
		for (int j = 0; j < M && can; j++) {
			if (NOT[i][S + j]) continue;

			for (int k = 0; k < D; k++) {
				if (NOT[S + j][S + M + k] || NOT[i][S + M + k]) continue;

				map<int, int> cnt;
	
				for (int a = 0; a < IN[i]; a++) {
					cnt[C[i][a]] += 1;
				}
				for (int a = 0; a < IN[S + j]; a++) {
					cnt[C[S + j][a]] += 1;
				}
				for (int a = 0; a < IN[S + M + k]; a++) {
					cnt[C[S + M + k][a]] += 1;
				}

				unsigned long long curr = 1LL;

				for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {

					if(multiplication_is_safe(curr, BR[it->first])){
						curr *= BR[it->first];	    
					}else{
						can = 0;
						break;
					}
				}
				if(addition_is_safe(curr, ans)){
					ans += curr;	    
				}else{
					can = 0;
					break;
				}
			}
		}
	}
	if(!can || ans > 1000000000000000000LL) {
		cout << "too many\n";
	} else {
		cout << ans << "\n";
	}
  
	return 0;
}
