import java.util.*;

class GStack<T> {
	static int top;
	Object [] stack;
	
	/*
	 * ������();
	 * peek();
	 * push();
	 * pop();
	 * �Լ� ���� ����.
	 */
}

public class test  {
	
	public static void main(String[] args) {
		
		String infix = new String("2.0*3.0-((4.0+5.0)*2.0)-4.0)=");
		StringTokenizer st = new StringTokenizer(); //�� �̿��� ��ūȭ �۾�
		GStack<String> StringStack = new GStack<String>(); 
		//�и��� ��ū�� �̿��Ͽ� StirngType�� Stack�� �ְ� postfixȭ ��Ŵ.
		
		GStack<Double> DoubleStack = new GStack<Double>();
		//postfix�� String�� �ٽ� ��ūȭ���� ParseDoubleȤ�� ParseInteger�Լ��� ����Ͽ�
		//String -> Double or integer�� ��ȯ ��Ų�� �ٽ� ��ūȭ ���� ���ÿ� �ְ�
		//����� �������ش�.
		
		/*
		 * main�Լ��� �ƴ� public class ���� �Լ����� �Լ��� �ۼ��ص� �ǰ�,
		 * �̿ܿ� ArrayList�� �̿��Ͽ� ��ūȭ�� ����۾��� �� �ս��� ���� �ǰ�,
		 * ���� ������� �ֽ��ϴ�. �޸𸮿� �ӵ��� �߿�ġ �ʰ� ���� ������
		 * �پ��� ������� ������ ���ñ� �ٶ��ϴ�.
		 */
				
	}
}

