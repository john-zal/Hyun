import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 대문자 입력
		int N = sc.nextInt();
		for (int j = 1; j <= N; j++) { //입력받은 만큼의 사이클
			for (int i = 0; i < j; i++) { // 0, 1, 2, 3, 4 (총 5번)숫자 만큼 별 찍기
				System.out.print("*");
			}
			System.out.println("");
		}
	}
}