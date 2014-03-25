#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-7;

int N;

bool eq(double x, double y) {
  return fabs(x - y) < EPS;
}

int main(void) {
  cin >> N;

  cout << "INTERSECTING LINES OUTPUT\n";

  for (int i = 0; i < N; i++) {
    double x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double m1 = (y2 - y1) / (x2 - x1);
    if (eq(x2 - x1, 0)) m1 = 0;

    double m2 = (y4 - y3) / (x4 - x3);
    if (eq(x4 - x3, 0)) m2 = 0;

    double b1 = y1 - x1 * m1;
    double b2 = y3 - x3 * m2;

    bool m1v = eq(x1, x2);
    bool m2v = eq(x3, x4);       

    if (m1v && m2v) {
      if (x1 != x3) {
    printf("NONE\n");
      } else {
    printf("LINE\n");
      }
    } else if (m1v) {
      printf("POINT %.2lf %.2lf\n", x1, x1 * m2 + b2);
    } else if (m2v) {
      printf("POINT %.2lf %.2lf\n", x2, x2 * m1 + b1);
    } else if ((eq(m1, m2) && !eq(b1, b2))) {
    printf("NONE\n");
    } else if (eq(m1, m2) && eq(b1, b2)) {
      printf("LINE\n");
    } else {
      double xp = (b2 - b1) / (m1 - m2);
      printf("POINT %.2lf %.2lf\n", xp, m1 * xp + b1);
    }
  }

  cout << "END OF OUTPUT\n";

  return 0;
}
