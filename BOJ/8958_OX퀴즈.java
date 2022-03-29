import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 대문자 입력
		String str;
		
		int oxlength = sc.nextInt();
		int[] score = new int[oxlength];
		
		for (int j = 0; j < oxlength; j++) {
			str = sc.next();
			int cnt = 0;
			
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == 'O') {
					score[j] += cnt + 1;
					cnt++;
				} else if (str.charAt(i) == 'X') {
					cnt = 0;
				}
			}			
		}
		for(int i = 0; i<score.length; i++) {
			System.out.println(score[i]);	
		}
	}
}