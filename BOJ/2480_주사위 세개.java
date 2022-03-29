package programmers;

import java.util.Arrays;
import java.util.Scanner;

//14681 사분면 고르기
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 변수
		int[] dice = new int[3];
		int answer = 0;
		for (int i = 0; i < dice.length; i++) {
			dice[i] = sc.nextInt();
		}
		//
		if ((dice[0] == dice[1]) && (dice[1] == dice[2]) && (dice[0] == dice[2])) {
			// 셋 눈금 다 같을 때
			answer = 10000 + (dice[0] * 1000);

		} else if ((dice[0] == dice[1]) || (dice[0] == dice[2])) {
			// 둘 눈금만 같을 때
			answer = 1000 + (dice[0] * 100);
		} else if ((dice[1] == dice[2])) {
			answer = 1000 + (dice[1] * 100);
		} else {
			// 모두 다를 때		
			Arrays.sort(dice);
			answer = dice[2] * 100;
		}
		System.out.println(answer);
	}
}