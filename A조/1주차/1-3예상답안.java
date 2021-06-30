public class Jeon {
	public static void main(String[] args) {
		
		int a[][] = { {2, -1, 3}, {1, 1, -1}, {2, 3, 0} };
		
		System.out.println("Matrix");
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
		System.out.println("Transposed matrix");
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) { 
				System.out.print(a[j][i] + " ");
			}
			System.out.println();
		}
		
	}
}