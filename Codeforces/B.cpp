#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

bool dp[10001][10001];

int main() {
    vector<long long> nums;
    long long temp;

    int len;

    cin >> len;

    string s;

    getline(cin, s);
    getline(cin, s);

    istringstream ss(s);

    for(int i = 0; i < len; ++i) {
		ss >> temp;
		nums.push_back(temp);
    }

    int ret = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i != j) {
				if (nums[i] == -nums[j]) {
					if (dp[i][j] == false && dp[j][i] == false) {
						dp[i][j] = true;
						dp[j][i] = true;
						ret++;
					}
				}
			}
		}
	}
	cout << ret << endl;
}

