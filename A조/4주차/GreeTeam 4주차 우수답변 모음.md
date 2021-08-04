1번문제

```java
package homework_3week_1;
import java.util.*;
public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scanner = new Scanner(System.in);
		int[] lowerAlphaCnt = new int[26];
		int[] upperAlphaCnt = new int[26];
		
		String strData;
		System.out.print("문자열 입력: ");
		strData = scanner.nextLine();
		int n = strData.length();
		char ch;
		for (int i=0;i<n;i++) {
			
			ch = strData.charAt(i);
		
			if ((ch >='a'&& ch <='z') || (ch >= 'A' && ch <= 'Z')) {
				
				if(Character.isUpperCase(ch)) 
					upperAlphaCnt[ch-'A']++;
				else
					lowerAlphaCnt[ch-'a']++;
			}
		}
        
		System.out.println("< 결과 >");
		int totalCnt;
        for (int i=0;i<26;i++) {
			
			totalCnt = lowerAlphaCnt[i] + upperAlphaCnt[i];
			System.out.print((char)('A'+ i) + " = " +upperAlphaCnt[i]+"개, ");
			System.out.print((char)('a'+ i)+ " = "+ lowerAlphaCnt[i]+"개 ");
			System.out.println((char)('A'+ i)+ " + "+(char)('a'+ i)+" = "+ totalCnt+"개");
			
		}
	}

```

2번문제

```java
package Problem;
import java.util.*;
public class nyam_3rd_Homework2 {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String words;
		int count= 0;
		words = new String(scanner.nextLine());
		
		String a[] = words.split(" ");
		for(int i=0; i< a.length; i++) {
			if(a[i].contains("a") || a[i].contains("A") || a[i].contains("n") || a[i].contains("N"))
				count++;				
		}
		System.out.println("a(A), n(N)이 포함된 단어의 수 : " + count +"개");
	}

}
```

자바 6번

```java
package Problem;
import java.util.*;
public class practice6_10sTimerGame {

	static int timer10s (String name) {
/// 엔터키 버퍼에서 어떻게 뺴내지
		Scanner scanner = new Scanner(System.in);
		
		System.out.println(name + " 시작 <Enter>키>>");
		Calendar first = Calendar.getInstance();
		
		int sec1 = first.get(Calendar.SECOND);
		if(scanner.nextLine() != null);
		System.out.print("");
		System.out.println("   현재 초 시간 = " + sec1);
		
		System.out.println("10초 예상 후 <Enter>키>>");
		if(scanner.nextLine() != null);
		Calendar second = Calendar.getInstance();
		
		int sec2 = second.get(Calendar.SECOND);
		System.out.println("   현재 초 시간 = " + sec2);
		
		int sec3 = sec2 - sec1;
		if(sec3 < 0) sec3 += 60;
		return sec3;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Calendar first = Calendar.getInstance();
		int n1 = timer10s("황기태");
		int n2 = timer10s("이재문");
		System.out.print("황기태의 결과 " + n1 +", 이재문의 결과 "+ n2);
		
		n1 = Math.abs(10 - n1);
		n2 = Math.abs(10 - n2);
		if( n1 == Math.max(n1, n2))
			System.out.print(", 승자는 이재문");
		else 
			System.out.print(", 승자는 황기태");
	}

}

```

자바10번

```java
package Problem;
import java.util.*;

class Person{
	
	private String name;
	Person(){};
	Person(String name){ this.name = name;}
	String getName() { return this.name;}
}


public class practice10_Gambling {

	static boolean gambling (Person p) {
		
		Scanner scanner = new Scanner(System.in);
		int num[] = new int[3];
		
		System.out.println("["+ p.getName()+"]:<Enter>");
		if(scanner.nextLine() != null);
		
		for(int i=0; i<3; i++) {
			num[i] = (int) (Math.random()*3 + 1);
			System.out.print(num[i] + "  ");
		}
					
		if(num[0] == num[1])
			if(num[1] == num[2]) return true;
			
		return false;
			
	}
	
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		Person person1, person2;
		boolean check;
		
		System.out.print("1번째 선수 이름>>");
		person1 = new Person(scanner.nextLine());
		
		System.out.print("2번째 선수 이름>>");
		person2 = new Person(scanner.nextLine());
		
				
		while(true) {
			
			check = gambling(person1);
			if(check) {
				System.out.println(person1.getName() + "님이 이겼습니다!");
				break;
			}
			else System.out.println("아쉽군요!");
			
			check = gambling(person2);
			if(check) {
				System.out.println(person2.getName() + "님이 이겼습니다!");
				break;
			}
			else System.out.println("아쉽군요!");
		}

	}

	
}

```

자바 11번

```java
package Problem;
import java.util.*;
public class WordChange {

	static int wantIndex (StringBuffer all, String changeBefore) {
		
		int index,i,j;
		
		for( i=0; i< all.length(); i++) {
			if(changeBefore.charAt(0) == all.charAt(i)) {
				index= i;
				for( j=1; j< changeBefore.length(); j++) {
					if(i+j > all.length()) break;
					if((changeBefore.charAt(j) != all.charAt(i+j))) break; // 중간에 틀렸다
					if(j == changeBefore.length() -1) return i; // 다 똑같다. 처음 단어 시작 인덱스 리턴
				}			
			}
		}
		return -1; // 찾지 못함
	}
	public static void main(String[] args) {
		
		int wordCount;
		Scanner scanner = new Scanner(System.in);
		StringBuffer all = new StringBuffer("우리는 love Java Programming");
		String word;
		while(true) {
			
			System.out.print ("명령: ");
			word = scanner.nextLine();
			
			if(word.equals("그만")) System.exit(0);
			
			StringTokenizer st = new StringTokenizer(word, "!"); // 명령어 분리
			if(st.countTokens() !=2) {
				System.out.println ("잘못된 명령입니다!");
				continue;
			}
			
			String changeBefore =  st.nextToken(); // 
			wordCount = wantIndex (all,  changeBefore);
			if(wordCount == -1) System.out.println("찾을수 없습니다!");
			else {
				all.replace(wordCount, wordCount + changeBefore.length() , st.nextToken());
			}
			System.out.println(all);
		}
	}

}

```

절대값 힙 문제

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define MAX 100000


typedef struct {
	int key;
}element;

typedef struct Heaptype {
	element heap[MAX];
	int heap_size;
}Heaptype;

Heaptype* create(){
	return (Heaptype*)malloc(sizeof(Heaptype));
}

void init(Heaptype* p) {
	p->heap_size = 0;
}

int abs(element node) {
	return node.key > 0 ? node.key : -(node.key);
}

void insert(Heaptype* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while (i != 1 && abs(item) < abs(h->heap[i / 2])) //
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2; 
	}

	h->heap[i] = item;
}

element delete(Heaptype* h) {

	int parent, child;
	element item, temp;

	item = h->heap[1]; // 제일 큰 노드 반납
	
	temp = h->heap[(h->heap_size)--]; // 제일 마지막 노드 가져오고 사이즈 하나 줄이기
	parent = 1;
	child = 2; // 자식 노드 인덱스

	while (child <= h->heap_size) {
		if (child < h->heap_size && abs(h->heap[child]) > abs(h->heap[child + 1]))
			child++; // 2개의 자식 노드 중 더 작은거 찾기
			
		if (abs(temp) <= abs(h->heap[child])) break; // 제자리 찾았을 때

		h->heap[parent] = h->heap[child]; // 한 단계 아래로
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;


}

element want_node(Heaptype* h, element node) {

	element temp;
	
	if (node.key > 0 && h->heap_size > 0) { // 뽑은 노드가 양수인 경우
		
		temp = delete(h); //하나 더 빼오기
		if (abs(temp) == abs(node) && temp.key < 0) // 절대값 같은 음수를 찾았다
		{
			insert(h, node);	// 양수는 집어넣고
			node = temp;	// 음수값 node에 저장
			return node;
		}
		else { 
			if (temp.key > 0 && abs(temp) == abs(node)) // 1,1,-1 인 경우
				node = want_node(h, node);
			insert(h, temp);		// 원하는 값이 아니면 다시 넣어주기
		}
		
	}
	return node;
}
int main() {

	int N, num;
	element data,node;
	Heaptype* h;
	h = create();
	init(h);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {

		scanf("%d", &num);
		if (num == 0) {

			if (h->heap_size <=0) printf("0\n");
			else {
				node = delete(h);
				node = want_node(h, node);
				printf("%d\n", node);
			}
		}

		else {
			data.key = num;
			insert(h, data);
		}
	}
}
```

