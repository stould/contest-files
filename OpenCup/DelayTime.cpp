#include <bits/stdc++.h>

using namespace std;

double H1, H2;
double T1, T2;

int main(void) {
	cin >> H1 >> T1 >> H2 >> T2;

	double A = H1-H2, B = (2.*H1*T2) - (2.*H2*T1);
	double C = (H1*T2*T2) - (H2*T1*T1);

	double disc = B*B - (4. * A *C);

	//cout << disc << "\n";
  
	double x1 = (-B + sqrt(disc)) / (2.*A);
	double x2 = (-B - sqrt(disc)) / (2.*A);

	cout << min(abs(x1), abs(x2)) << "\n";
  
	//cout << x1 << " " << x2 << "\n";
  
	return 0;
}
