package programmers;

import java.util.Arrays;

class Solution {
	public int[] solution(int[] array, int[][] commands) { // 1 5 2 6 3 7 4
		int[] answer = new int[commands.length]; // 답
		// 배열 자르기

		for (int i = 0; i < commands.length; i++) { // 0 1 2
			int[] cutarr = Arrays.copyOfRange(array, commands[i][0] - 1, commands[i][1]);
			Arrays.sort(cutarr);
			answer[i] = cutarr[commands[i][2]-1];
		}
		return answer;
	}
}