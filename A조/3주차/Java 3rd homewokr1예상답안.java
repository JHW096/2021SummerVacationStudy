public class test {
	public static void main(String[] agrs) {
		
		String str = new String("");
		int small[] = new int[26];  //���ĺ� ����
		int large[] = new int[26];
		
		for(int i = 0; i<str.length(); i++) {
			for(int j = 0; j<26; j++) {
				if(str.charAt(i) == 'a' + j) {		//�ҹ��� ���� Ȯ��
					small[j]++;
				 break;
				}
				 
				if(str.charAt(i) == 'A' + j) {		//�빮�� ���� Ȯ��
					large[j]++;
					break;
				}
			}
		}
		for(int n = 0; n<26; n++) {
			int sum = small[n] + large[n];
		System.out.print((char)('a' + n) + "=" + small[n] + "�� " + (char)('A' + n) + "=" + large[n] + "��  " + (char)('a' + n) + "+" + (char)('A' + n) + "�� ���� " + sum + "��");
		System.out.println();
		}
	}
}