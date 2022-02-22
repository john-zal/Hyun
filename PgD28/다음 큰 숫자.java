package programmers;

import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int n = 15;

		System.out.println(s.solution(n));

	}
}

class Solution {
	public int solution(int n) {
		String bin = Integer.toBinaryString(n);
		int Ncnt = 0;
		int Ncnt2 = 0;
		int answer = n;
		boolean check = true;
		for (int i = 0; i < bin.length(); i++) {
			if (bin.charAt(i) == '1') {
				Ncnt++;
			}
		}
		while (check) {
			answer++;
			bin = Integer.toBinaryString(answer);
			for (int i = 0; i < bin.length(); i++) {
				if (bin.charAt(i) == '1') {
					Ncnt2++;
				}
			}
			if (Ncnt2 != Ncnt) {
				Ncnt2 = 0;
			} else {
				check = false;
			}
		}
		return answer;
	}
}