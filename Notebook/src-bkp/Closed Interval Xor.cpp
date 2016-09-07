//xor [a .. b]
uInt f(uInt a) {
     uInt res[] = {a,1,a+1,0};
     return res[a%4];
}

uInt getXor(uInt a, uInt b) {
	if (a == b) return a;
	uInt ans = (f(b)^f(a-1));
	return ans;
}
