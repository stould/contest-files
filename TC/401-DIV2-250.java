import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.Math.*;

public class DreamingAboutCarrots {
	public int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
		return gcd(abs(x1 - x2), abs(y1 - y2)) - 1;
	}
	public int gcd(int a, int b) {
		if(a == 0) {
			return b;
		} else {
			return gcd(b % a, a);
		}
	}
}


// Powered by FileEdit
