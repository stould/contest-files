#include <iostream>

using namespace std;

int main(void) {
	int N, A, B;
	cin >> N;
	for ( ; N--; ) {
		cin >> A >> B;
		cout << (int) (A / 3) * (int) (B / 3) << "\n";
	}
	return 0;
}
