#include <iostream>
#include <cmath>

using namespace std;

int X, Y, S;

int main(void) {
  cin >> X >> Y >> S;

  int df = abs(X) + abs(Y);

  if (df > S || (df % 2 != S % 2)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  
  return 0;
}
