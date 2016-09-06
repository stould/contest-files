double area(double a, double b, double c) {
	double s = (a + b + c) / 2.0;

	double area = sqrt(s * (s - a) * (s - b) * (s - c));

	return area;
}
