#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

string S;

int main(void) {
	cin >> S;
	int N = (int) S.size();
    string ans = "";

    for (char c = 'z'; c >= 'a'; c--) {
		if (S.find(c) != string::npos) {
			int id = 0;

			for (char b = c; b >= 'a'; b--) {
				for (int i = id; i < N; i++) {
					if (S[i] == b) {
						ans += b;
						id = i;
					}
				}
			}					
			break;
		}
    }

    cout << ans << endl;

    return 0;
}
