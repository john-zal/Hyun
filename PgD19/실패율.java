package programmers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);

		int N = 4;
		int[] stages = { 1, 2, 3, 2, 1 };
		System.out.println(s.solution(N, stages));
	}
}

class Solution {
	public int[] solution(int N, int[] stages) {

		int[] answer = new int[N];
		int fail = 0; // 탈락자
		Arrays.sort(stages);
		ArrayList<Integer> num = new ArrayList<Integer>(); // 살아남은 유저

		// 실패율 배열 저장
		int[][] failper = new int[N][2];
		double[] failper2 = new double[N];

		// (1, 2, 2, 2, 3, 3, 4, 6)

		for (int i = 0; i < stages.length; i++) {
			num.add(stages[i]);
		}

		for (int i = 1; i <= N; i++) { // 스테이지는 1단계에서 5단계까지 1, 2, 3, 4, 5
			failper[i - 1][1] = num.size(); // 참가한 사람들 수
			for (int j = 0; j < num.size(); j++) { // 살아남은 유저 만큼의 for

				if (num.get(j) <= i) { // 1 2 2 2 3 3 4 6
					fail++; // 탈락자 명단 추가
				}
			}
			failper[i - 1][0] = fail;

			failper2[i - 1] = (double) failper[i - 1][0] / (double) failper[i - 1][1];
			if (failper[i - 1][0] == 0 && failper[i - 1][1] == 0) {
				failper2[i-1] = 0;
			}
			//System.out.println(failper[i - 1][0] + "/" + failper[i - 1][1]);
			//System.out.println(i + "번째 실패율" + failper2[i - 1]);

			while (num.remove(Integer.valueOf(i)))
				; // 탈락자 정리
			fail = 0;
		}

		// 실패율 구하기

		for (int i = 0; i < N; i++) {
			double max = -1; // 실패율 0 고려
			int maxIndex = 0;
			for (int j = 0; j < N; j++) {
				if (failper2[j] > max) {
					max = failper2[j];
					maxIndex = j;
				}
			}
			failper2[maxIndex] = -1;
			answer[i] = maxIndex + 1;
		}

		/*for (int i = 0; i < answer.length; i++) {
			System.out.println(answer[i]);
		}*/
		return answer;
	}
}