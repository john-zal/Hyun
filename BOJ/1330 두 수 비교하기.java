import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 int A = sc.nextInt();
		 int B = sc.nextInt();
		 String answer = "";
		 if(A>B) {
			 answer = ">";
		 }else if(A<B) {
			 answer = "<";
		 }else {
			 answer = "==";
		 }		
		System.out.println(answer);
	}
}