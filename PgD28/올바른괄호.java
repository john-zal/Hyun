package programmers;

import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		String ss = "()()))((";

		System.out.println(s.solution(ss));

	}
}

class Solution {
	boolean solution(String s) {
		boolean answer = true;
		int cntA = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				cntA++;
			} else if (s.charAt(i) == ')') {
				cntA--;
				if (cntA <= -1) {
					answer = false;
				}
			}
		}
		if (cntA != 0) {
			answer = false;
		}
		return answer;
	}
}