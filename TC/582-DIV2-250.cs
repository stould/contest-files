using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;

public class SemiPerfectSquare
{
	public string check(int N)
	{		
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i * j * j == N) {
					return "Yes";
				}
			}
		}
		return "No";		
	}
}
//Powered by [KawigiEdit] 2.0!