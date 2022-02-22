package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int[][] board = { { 0, 1, 1, 1 }};

		System.out.println(s.solution(board));

	}
}

class Solution {
	public int solution(int[][] board) {
		int answer = 0;
		int[][] dp = new int[board.length][board[0].length];

		for (int i = 0; i < board.length; i++) {
			if (i == 0) { // 0일때 초기 셋팅해준다
				for (int j = 0; j < board[0].length; j++) {
					dp[i][j] = board[i][j];
				} // 0111
			} else {
				for (int j = 0; j < board[i].length; j++) {
					if (j == 0) {
						dp[i][j] = board[i][j]; // 세로도 초기값 세팅해준다 0110
					} else {
						// 주요 로직 구현 [위], [왼쪽 대각선 위], [왼쪽] 각각 값을 구함 셋을 비교해서 가장 작
						// 셋을 비교해서 가장 작은 값에 +1 해준게 사각형의 최대 길이
						if(board[i][j] == 0) {
							dp[i][j] = 0;
							continue;
						}
						int[] min = new int[3];
						min[0] = dp[i - 1][j - 1]; // 대각선 값
						min[1] = dp[i - 1][j]; // 위 값
						min[2] = dp[i][j - 1]; // 왼쪽 값
						Arrays.sort(min); // 최소값 구하기 위한 정렬
						dp[i][j] = min[0] + 1; //최소값에 +1 해준게 한 변의 길이
					}

				}
			}
		}
		//최대 길이
		int max = 0;
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				if(max<dp[i][j]) {
					max = dp[i][j];
				}
			}
		}
		answer = max*max;
		return answer;
	}
}