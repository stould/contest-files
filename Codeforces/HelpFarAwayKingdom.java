import java.util.Scanner;

public class HelpFarAwayKingdom {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String num = input.nextLine().replace(".", ",");
		String[] a = String.valueOf(num).split(",");
		
		
		if(num.endsWith("9") && (Double.parseDouble(a[1]) * 0,01) < 0.5) {
			System.out.println(Math.round(Integer.parseInt(num)));
		} else if(!String.valueOf(num).endsWith("9") && (Double.parseDouble(a[1]) * 0,01) > 0.5) {
			System.out.println(Math.round(Integer.parseInt(num)) + 1);
		} else {
			System.out.println("GOTO Vasilisa.");
		}
	}
}
