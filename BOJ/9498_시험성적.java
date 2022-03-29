import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 int a = sc.nextInt();
		 String answer = "";
		 if(a>=90) {
			 answer = "A";
		 }else if(a>=80 && a<=89) {
			 answer = "B";
		 }else if(a>=70 && a<=79){
			 answer = "C";
		 }else if(a>=60 && a<=69) {
			 answer = "D";
		 }else {
			 answer = "F";
		 }
		System.out.println(answer);
	}
}