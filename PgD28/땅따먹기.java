import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int[][] land = { { 1, 2, 3, 5 }, { 5, 6, 7, 100 }, { 4, 3, 2, 1 } };

		System.out.println(s.solution(land));

	}
}

class Solution {
	int solution(int[][] land) {
		int answer = 0;
		int[][] dp = new int[land.length][land[0].length];
		
		for (int i = 0; i < land.length; i++) { // 초기 첫 줄만 세팅
			for (int j = 0; j < land[i].length; j++) {				
				int max = 0;
				if (i == 0) {
					dp[i][j] = land[i][j]; // 1 2 3 5
				} else {
					for (int k = 0; k < land[i].length; k++) { // 이후 위에 값
							if (j == k) { // 0  0
								continue;
							} else if (max < dp[i - 1][k]) { // max 값
								max = dp[i - 1][k];
							}
						}
					}
				dp[i][j] = land[i][j] + max;
			}
		}
		for(int i = 0; i<dp[dp.length-1].length; i++) { //맨 아래 최대값
			if(answer < dp[dp.length-1][i]) {
				answer = dp[dp.length-1][i];
			}
		}
		return answer;
	}
}