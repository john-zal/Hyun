import java.util.Scanner;
//2753 윤년
public class Main {
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 //변수
		 int a = sc.nextInt();
		 int answer = 0;
		 
		 if((a%4 == 0 && a%100 != 0) || a%400 == 0) {
			 answer = 1;
		 }		 
		System.out.println(answer);
	}
}