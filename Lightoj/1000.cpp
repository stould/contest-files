#include <iostream>

using namespace std;

int main() {
  int n, a, b, counter = 1;
  
  cin >> n;

  while(n > 0) {
    cin >> a >> b;
    cout << "Case " << counter++ << ": " << (a + b) << endl;
    n--;
  }
  return 0;
}
