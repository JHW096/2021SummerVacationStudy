import java.util.Scanner;

public class Jeon { 
	public static void main(String ares[]) {
		
		Scanner Myscan = new Scanner(System.in);
		
		System.out.print("층을 입력하시오.");
		int n = Myscan.nextInt();
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n+1; j++) {
				if(i > j) {
					System.out.print(" ");
				}
				else if(i != j) {
					System.out.print("*");
				}
			}
			System.out.println();
		}
		
		
	}
}