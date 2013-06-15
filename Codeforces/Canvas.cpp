#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int n, temp, count = 0;
	vector<int> v;

	string buff;

	cin >> n;

	bool memo[n];

	memset(memo, false, sizeof memo);

	getline(cin, buff);
	getline(cin, buff);

	istringstream ss(buff);

	while(ss >> temp) {
		v.push_back(temp);
	}
    int ret = 0;
	for(unsigned i = 0; i < v.size(); i++) {
		for(unsigned j = 0; j < v.size(); j++) {
			if(i != j && v[i] == v[j] && memo[i] == false && memo[j] == false) {
				count++;
				memo[i] = memo[j] = true;

				if(count == 2) {
                    ret++;
                    count = 0;
				}
				continue;
			}
		}
	}
    cout << ret << endl;
	return 0;
}
