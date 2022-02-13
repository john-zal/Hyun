package programmers;

import java.util.ArrayList;


public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);

		int[] answers = { 3, 3, 2, 1, 5 };
		System.out.println(s.solution(answers));
	}
}

class Solution {
	public int[] solution(int[] answers) {
		int[] p1 = { 1, 2, 3, 4, 5 };// 12345
		int[] p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };// 21232425
		int[] p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };// 3311224455

		
		int[] score = new int[3]; // 맞은 점수 //p1 p2 p3
		ArrayList<Integer> arr = new ArrayList<>();

		for (int i = 0; i < 3; i++) {
			score[i] = 0;
		}

		for (int i = 0; i < answers.length; i++) { // 정답의 길이 // 1 2 3 4 5
			if (p1[i % p1.length] == answers[i])
				score[0] += 1; // 0%5 =0 1%5 = 1
			if (p2[i % p2.length] == answers[i])
				score[1] += 1;// 0% 8
			if (p3[i % p3.length] == answers[i])
				score[2] += 1;
		}

		int max = 0;
		int rank = 0;
		int cnt = 0; //모두가 0점일때
		
		for(int i = 0; i<score.length; i++) { //제일 많이 맞은사람
			if(score[i] != 0 && max<score[i]) {
				max = score[i];
				rank = i;
			}
		}
		for(int i = 0; i<score.length; i++) {
			if(max == score[i]) { //최대값  여러개?
				arr.add(i+1);
			}
		}
		int[] answer = new int[arr.size()];
		for(int i=0; i<arr.size(); i++) {
			answer[i] = arr.get(i);
			System.out.println(answer[i]);
		}
		return answer;
	}
}