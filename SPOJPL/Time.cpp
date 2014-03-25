#include <iostream>
using namespace std;
int T, N;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for ( ; T--; ) {
		cin >> N;

		if (N % 6 == 0) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	return 0;
}
