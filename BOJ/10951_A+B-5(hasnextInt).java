import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
			while(sc.hasNextInt()) {
				// 정수를 입력받지 않으면  false를 반환하는 스캐너 메소드
				// hasnext는 boolean 값으로 반환된다.
				int A = sc.nextInt();
				int B = sc.nextInt();
				System.out.println(A+B);
		}
			sc.close();
	}
}