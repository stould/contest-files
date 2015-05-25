#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

double a, b, c;

double getDelta(){
    return b*b - (4*a*c);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    double delta = getDelta();
    if(delta < 0 || a <= 0){
        cout << "Impossivel calcular\n";
    }else{
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("R1 = %.5lf\nR2 = %.5lf\n", x1, x2);
    }
    return 0;
}
