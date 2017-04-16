//Area de um Poligono Convexo
double area() {
	int N = 4;

	//Points
	int[] x = { 2, -4, 5, 2 };
	int[] y = { 5, 3, 1, 5 };
	
	double ma = x[N - 1] * y[0], mb = x[0] * y[N - 1];

	for (int i = 0; i < N - 1; i++) {
		ma += (x[i] * y[i + 1]);
		mb += (x[i + 1] * y[i]);
	}

	double ans = Math.abs((ma - mb) * 0.5);
}
