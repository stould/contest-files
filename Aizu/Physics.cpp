#include <iostream>

using namespace std;


int main(void)
{
	double v, t, y, n;

	while(cin >> v ) {
		t = v/9.8;
		y = 4.9*t*t;

		for( n=0; 5*n-5<y; n++ );

		cout << n << endl;
	}
	return 0;
}
