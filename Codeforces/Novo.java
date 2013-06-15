import java.util.Scanner;

public class B {
	public void solve() {
		Scanner sc = new Scanner(System.in);
		String mn = sc.nextLine();
		double aux = Double.parseDouble(mn);
		String ret = "";
		if (mn.contains(".")) {
			int indPartint = mn.indexOf(".");
			int indPartFrac = mn.indexOf(".") + 1;
			String partInt = "";
			partInt = mn.substring(0, indPartint);
			String partFrac = mn.substring(indPartFrac);
			int MOD = partInt.length() % 3;
			ret += "$";
			for (int i = 0; i < partInt.length(); i++) {
				if ((i % 3) - MOD == 0 && i != 0) {
					ret += ("," + partInt.charAt(i));
				} else {
					ret += partInt.charAt(i);
				}
			}
			if (Long.parseLong(partFrac) == 0) {
				ret += ".00";
			} else {
				while (partFrac.length() < 2)
					partFrac += "0";
				ret += "." + partFrac.substring(0, 2);
			}
		} else {
			ret += "$";
			int MOD = (mn.length()) % 3;
			for (int i = 0; i < mn.length(); i++) {
				if ((i % 3) - MOD == 0 && i != 0) {
					ret += "," + mn.charAt(i);
				} else {
					ret += mn.charAt(i);
				}
			}

			ret += ".00";
		}
		if (aux < 0 && ret.charAt(2) == ',') {
			ret = ret.substring(0, 1) + ret.substring(3, ret.length());
		}
		ret = ret.replace("-", "");
		if (aux >= 0) {
			System.out.println(ret);
		} else {
			System.out.println("(" + ret + ")");
		}
	}

	public static void main(String[] args) {
		new B().solve();
	}
}