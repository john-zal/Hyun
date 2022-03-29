import java.util.Scanner;
//14681 사분면 고르기
public class Main {
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 //변수
		 int x = sc.nextInt();
		 int y = sc.nextInt();
		 int answer = 0;
		 
		 if(x>0 && y>0) {
			 answer = 1;
		 }else if(x<0 && y>0) {
			 answer = 2;
		 }else if(x<0 && y<0) {
			 answer = 3;
		 }else if(x>0 && y<0) {
			 answer = 4;
		 }
		System.out.println(answer);
	}
}