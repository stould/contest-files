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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class NetworkXZeroOne {
public:

	string reconstruct(string);
};

string NetworkXZeroOne::reconstruct(string message) {
	int i;
	int j;
	int N = (int) message.size();
	
	for ( ; message.find('?') != string::npos; ) {
		for (i = 0; i < N; i++) {
			if (message[i] != '?') {
				int f[2];
				
				f[0] = f[1] = 0;
				
				for (j = i; j < N; j++) {
					if (message[j] == 'x') {
						f[0] += 1;
					} else if (message[j] == 'o') {
						f[1] += 1;
					} else {
						if ((j - i + 1) % 2 == 0) {
							if (f[0] < f[1]) {
								message[j] = 'x';
							} else {
								message[j] = 'o';
							}
						} else {
							break;
						}
					}
				}
				
				f[0] = f[1] = 0;
				
				for (j = i; j >= 0; j--) {
					if (message[j] == 'x') {
						f[0] += 1;
					} else if (message[j] == 'o') {
						f[1] += 1;
					} else {
						if ((i - j + 1) % 2 == 0) {
							if (f[0] < f[1]) {
								message[j] = 'x';
							} else {
								message[j] = 'o';
							}
						} else {
							break;
						}
					}
				}
	
			}
		}
	}
	
	return message;	
}

//Powered by [KawigiEdit] 2.0!