import java.util.*;

class GStack<T> {
	static int top;
	Object [] stack;
	
	/*
	 * 생성자();
	 * peek();
	 * push();
	 * pop();
	 * 함수 등을 구현.
	 */
}

public class test  {
	
	public static void main(String[] args) {
		
		String infix = new String("2.0*3.0-((4.0+5.0)*2.0)-4.0)=");
		StringTokenizer st = new StringTokenizer(); //를 이용해 토큰화 작업
		GStack<String> StringStack = new GStack<String>(); 
		//분리된 토큰을 이용하여 StirngType의 Stack에 넣고 postfix화 시킴.
		
		GStack<Double> DoubleStack = new GStack<Double>();
		//postfix된 String을 다시 토큰화시켜 ParseDouble혹은 ParseInteger함수를 사용하여
		//String -> Double or integer로 변환 시킨후 다시 토큰화 시켜 스택에 넣고
		//계산을 진행해준다.
		
		/*
		 * main함수가 아닌 public class 내부 함수에서 함수로 작성해도 되고,
		 * 이외에 ArrayList를 이용하여 토큰화와 계산작업을 더 손쉽게 만들어도 되고,
		 * 많은 방법들이 있습니다. 메모리와 속도는 중요치 않게 보고 있으니
		 * 다양한 방법으로 구현해 보시길 바랍니다.
		 */
				
	}
}

