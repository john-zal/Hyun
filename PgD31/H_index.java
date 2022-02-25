package programmers;

import java.util.Arrays;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		int[] citations = { 3, 1, 1, 1, 4 }; // 논문의 인용 횟수

		System.out.println(s.solution(citations));
	}
}

class Solution {
	public int solution(int[] citations) {
		int answer = 0;
		int h = 0;
		Arrays.sort(citations); // 1 1 1 3 4
		for (int i = 0; i < citations.length; i++) {
			h = citations.length - i; // 인덱스 한칸씩
			// citations[i] 이상 인용된 횟수 : h
			if (citations[i] >= h) {
				answer = h;
				break;
			}
		}
		return answer;
	}
}