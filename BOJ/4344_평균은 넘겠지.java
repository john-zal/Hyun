package programmers;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int C = sc.nextInt(); //테스트 케이스 개수
		for(int i = 0; i<C; i++) {// 0 1 2 3 4
			int N = sc.nextInt(); 
			int[] arr = new int[N];
			double avg = 0;
			for(int j = 0; j<arr.length; j++) {				
				arr[j] = sc.nextInt();
				avg += arr[j];
			}
			avg /=N; //평균
			
			double cnt = 0;
			for(int k = 0; k<arr.length; k++) { //평균 넘는 비율
				if(avg < arr[k]) {
					cnt++;
				}								
			}
			System.out.printf("%.3f%%\n", (cnt/N)*100);
		}		
	}
}