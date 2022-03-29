package bakjoon;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt(); // 0~23
		int M = sc.nextInt();// 0~59
		int h = H;
		int m = 0;
		
		m = M-45;
		
		if(M-45 < 0) {
			m = (M+60)-45;
			h--;
			if(h < 0) {
				h += 24;
			}
		}
		System.out.println(h+" "+m);
	}
}