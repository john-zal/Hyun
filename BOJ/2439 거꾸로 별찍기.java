package bakjoon;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String star = "";
		for(int i =1; i<=n; i++) {
			for(int j = 1; j <= n-i; j++) {
				star +=" ";
			}
			for(int k = 1; k<=i; k++) {
				star +="*";	
			}
			
				System.out.println(star);
				star = "";
		}		
	}
}