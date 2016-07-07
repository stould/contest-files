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

class ApplesAndOrangesEasy {
public:
    int maximumApples(int, int, vector <int>);
};

int ApplesAndOrangesEasy::maximumApples(int N, int K, vector <int> info) {
    vector<int> state(N, 0);
		
    int ans = 0;
	
    for (int i = 0; i < (int) info.size(); i++) {
        state[info[i] - 1] = 2;
    }
	
    while (1) {
        int cnt = 0;
		
        for (int i = 0; i < K; i++) {
            if (state[i] > 0) {
                cnt += 1;
            }
        }
        if ((cnt + 1) <= K / 2) {
            for (int i = 0; i < K; i++) {
                if (state[i] == 0) {
                    state[i] = 1;
                    break;
                }
            }
        } else {
            break;
        }
    }
	
    for (int i = K; i < N; i++) {	
        int curr = 0;
		
        for (int j = 0; j < K; j++) {
            if (state[i - j] > 0) {
                curr += 1;	
            }	
        }
        //		cout << i << " " << curr << endl;
        if ((curr + 1) <= K / 2) {
            state[i] = 1;
        } else if (curr > K / 2) {
            for (int j = 0; j < K; j++) {
                if (state[i - j] == 1) {
                    state[i - j] = 0;
                    break;
                }
            }
        }
    }
	
    for (int i = 0; i < N; i++) {
        //		cout << state[i] << " ";
        if (state[i] > 0) {
            ans += 1;
        }
    }
    return ans;	
}

//Powered by [KawigiEdit] 2.0!
