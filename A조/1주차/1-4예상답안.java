public class Jeon {
	public static void main(String[] args) {
		
		int k = args.length;
		
		double arr[] = new double[k];
		
		for(int i = 0; i < k; i++) {
			arr[i] = Double.parseDouble(args[i]);
		}
		
		double temp;
		
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k-1; j++) {
				if(arr[j] > arr[j+1]) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		for(int i = 0; i < k; i++) {
			System.out.print(arr[i] + " ");
		}
		
	}
}