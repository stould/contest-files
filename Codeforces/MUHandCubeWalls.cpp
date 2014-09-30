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

const int SHOLD = 1000000000;

int B[200005];
int N, W;
vector<int> SB, SW;

int KMP(vector<int> S, vector<int> K) {
    vector<int> T(K.size() + 1, -1);
	int ans = 0;

    if(K.size() == 0) {
        return 0;
    }
    for(int i = 1; i <= K.size(); i++) {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < S.size()) {
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) {
			ans += 1;
		}
    }

    return ans;
}

int main(void) {
	cin >> N >> W;



	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (i > 0) {
			SB.push_back(B[i] - B[i - 1]);
		}
	}

	for (int i = 0; i < W; i++) {
		cin >> B[i];
		if (i > 0) {
			SW.push_back(B[i] - B[i - 1]);
		}
	}

	if (W == 1) {
		cout << N << "\n";
	} else { 
		cout << KMP(SB, SW) << "\n";
	}

    return 0;
}
