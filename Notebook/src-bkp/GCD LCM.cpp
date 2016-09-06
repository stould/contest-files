//GCD - Maximo Divisor Comum
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
//*******************************************************
//LCM - Minimo Multiplo Comum
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
