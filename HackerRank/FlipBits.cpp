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

int bitFlip(vector < int > arr) {
    int N = (int) arr.size();  
    int ans = 0, def = 0;
    int best = 0, curr = 0, beg = 0;
    int bl = 0, br = 0;
    
    for (int i = 0; i < N; i++) {
		def += arr[i];
		if (arr[i] == 0) {
			curr += 1;
		} else {
			curr -= 1;
		}

        if (curr <= 0) {
            curr = 0;
            beg = i + 1;
        } else {
            if (curr >= best) {
                best = curr;
                bl = beg;
                br = i;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (i < bl || i > br) {
            ans += arr[i];
        } else {
            ans += (arr[i] == 0);
        }
    }

	ans = max(ans, def);
    
    return ans;
}

int main(void) {
	int N;
	while (cin >> N) {
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout << bitFlip(arr) << "\n";
	}
	return 0;
}
