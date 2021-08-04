자바 7장 4번

```java
package pb4;
import java.util.*;

public class main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		Vector <Integer> precipitation = new Vector<>();
		
		int input, sum = 0, size;
		
		while(true) {
			
			System.out.print("강수량 입력 (0 입력시 종료)>>");
			input = scanner.nextInt();
			
			if (input == 0) break;
			
			precipitation.add(input);
			
			size = precipitation.size();
			sum += precipitation.get(size-1);
			
			for (int i=0;i<size;i++) {
				
				int n = precipitation.get(i);
				System.out.print(n + " ");
			}
			
			System.out.println("\n현재 평균 " + sum/size);
			
	
		}
		
	}

}
```

7장 9번

```java
package Problem;
import java.util.*;

interface IStack<T>{
	T pop();
	boolean push(T ob);
}

class MyStack<T> implements IStack<T>{
	
	Vector<T> list;
	
	public MyStack(){
		list = new Vector<T>();
	}
	
	public T pop() {
		
		if(list.isEmpty()) return null;
		T item = list.get(list.size()-1);
		list.remove(list.size()-1);
		return item;
	}
	
	public boolean push(T ob) {
		return list.add(ob);
	}
}

public class P9_generic {
	public static void main(String[] args) {
		
		IStack<Integer> stack = new MyStack<Integer>();
		for(int i=0; i< 10; i++) stack.push(i);
		while(true) {
			Integer n = stack.pop();
			if(n==null) break;
			System.out.print(n + " ");
		}
	}
}
```

7장 11번

```java
package Problem;
import java.util.*;
class Nation{
	private String country, capital;
	
	Nation(String country, String  capital){
		this.country = country;
		this.capital = capital;
	}
	public String getCountry() {
		return this.country;
	}
	public String getCapital() {
		return this.capital;
	}
}
public class P11_1 {


	public static void main(String[] args) {
		
		int i;
		var list= new Vector<Nation>();
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("*** 수도 맞추기 게임을 시작합니다! ***");
		
		while(true) {
			
			System.out.println("입력:1, 퀴즈:2, 종료:3 >>");
			int n = scanner.nextInt();
			scanner.nextLine();
			
			switch(n) {
			case 1:
				System.out.println("현재 " + list.size()+ "개의 나라와 수도가 입력되어 있습니다.");
				
				while(true) {
					
					System.out.println("나라와 수도 입력 " + (list.size()+1));
					String s1 = scanner.next();
					if(s1.equals("그만"))
						break;					
					String s2 = scanner.next();
					Nation c = new Nation(s1,s2);
					
					for(i=0; i< list.size(); i++) {
						if(list.get(i).getCountry().equals(s1)) {
							System.out.println(c.getCountry() +"는 이미 있습니다!");
							break;
						}
					}
					if(i != list.size()) continue;
					
					list.add(c);
				}
				break;
				
			case 2:
				while(true) {
					
					int j = (int)(Math.random()*list.size());
					System.out.print(list.get(j).getCountry() + "의 수도는?");
					
					String s3 = scanner.nextLine();			
					if(s3.equals("그만")) break;
					if(list.get(j).getCapital().equals(s3))
						System.out.println("정답!");
					else System.out.println("아닙니다!");
				}
				break;
			case 3:
				
				System.out.println("게임을 종료합니다.");
				System.exit(1);
				
			}
		}

	}

}

```

11-2

```
package Problem;
import java.util.*;

public class P11_2 {
public static void main(String[] args) {
		
		int i;
		var list= new HashMap<String,String>();
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("*** 수도 맞추기 게임을 시작합니다! ***");
		
		while(true) {
			
			System.out.println("입력:1, 퀴즈:2, 종료:3 >>");
			int n = scanner.nextInt();
			scanner.nextLine();
			
			switch(n) {	
			case 1:			
				System.out.println("현재 " + list.size()+ "개의 나라와 수도가 입력되어 있습니다.");
				
				while(true) {
					
					System.out.println("나라와 수도 입력 " + (list.size()+1));
					String s1 = scanner.next();
					if(s1.equals("그만"))
						break;
					String s2 = scanner.next();
					Nation c = new Nation(s1,s2);
					
					if(list.containsKey(s1)) {
						System.out.println(s1 + "는 이미 있습니다!");
						continue;
					}					
					
					list.put(s1,s2);
				}
				break;
				
			case 2:
				while(true) {
					
					int j = (int)(Math.random()*list.size());
					
					Set<String> keys = list.keySet();
					Iterator<String> it = keys.iterator();
					
					String key = null;
					for(int p=0; p<=j; p++)
						key = it.next();
					
					System.out.print(key + "의 수도는?");
					String s3 = scanner.nextLine();
					
					if(s3.equals("그만")) break;
					if(list.get(key).equals(s3))
						System.out.println("정답!");
					else System.out.println("아닙니다!");
				}
				break;
				
			case 3:
				System.out.println("게임을 종료합니다.");
				System.exit(1);
				
			}
		}

	}
}

```

