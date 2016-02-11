using System;
using System.Collections;

public class BlackAndWhiteSolitaire {
	public int minimumTurns(string cardFront) {
		int i, N = cardFront.Length, ansA = 0, ansB = 0;
		
		for (i = 0; i < N; i++) {
			if (i % 2 == 0) {
				if (cardFront[i] == 'W') {
					ansA += 1;
				} else {
					ansB += 1;
				}
			} else {
				if (cardFront[i] == 'B') {
					ansA += 1;
				} else {
					ansB += 1;
				}
			}
		}
		
		return Math.Min(ansA, ansB);
	}
}


// Powered by FileEdit