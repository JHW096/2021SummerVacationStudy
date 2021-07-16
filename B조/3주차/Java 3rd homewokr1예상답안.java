public class test {
	public static void main(String[] agrs) {
		
		String str = new String("");
		int small[] = new int[26];  //알파벳 갯수
		int large[] = new int[26];
		
		for(int i = 0; i<str.length(); i++) {
			for(int j = 0; j<26; j++) {
				if(str.charAt(i) == 'a' + j) {		//소문자 갯수 확인
					small[j]++;
				 break;
				}
				 
				if(str.charAt(i) == 'A' + j) {		//대문자 갯수 확인
					large[j]++;
					break;
				}
			}
		}
		for(int n = 0; n<26; n++) {
			int sum = small[n] + large[n];
		System.out.print((char)('a' + n) + "=" + small[n] + "개 " + (char)('A' + n) + "=" + large[n] + "개  " + (char)('a' + n) + "+" + (char)('A' + n) + "의 합은 " + sum + "개");
		System.out.println();
		}
	}
}