import java.util.*;
import java.math.*;

public class MedianOfNumbers {
	public int findMedian(int[] numbers) {
		if(numbers.length == 1) return numbers[0];
		if(numbers.length % 2 == 0) return -1;
		Arrays.sort(numbers);
		return numbers[numbers.length / 2];
	}	
}


// Powered by FileEdit
