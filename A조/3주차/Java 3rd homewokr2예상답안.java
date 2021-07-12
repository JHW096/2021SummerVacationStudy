public class test {
	public static void main(String[] agrs) {
		
		String sentence = new String("");
		String words[] = sentence.toLowerCase().split(" ");
		
		int count = 0;
		
		
		for(int i = 0; i<words.length; i++) {	
			boolean A = false;
			boolean N = false;
			for(int j = 0; j<words[i].length(); j++) {
				
				if(words[i].charAt(j) == 'a') {
					A = true;
				}
					
				else if(words[i].charAt(j) == 'n') {
					N = true;
				}
				
			}
			if(A && N) {
				count++;
			}
		}
		System.out.println(count);
	}
}