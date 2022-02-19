package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		String ss = "1 -2 -3 -4";
		System.out.println(s.solution(ss));
	}
}

class Solution {
	public String solution(String s) {
		String answer = "";
		String[] str = s.split(" ");
		int[] num = new int[str.length];
		for(int i = 0; i<str.length; i++) {
			num[i] = Integer.parseInt(str[i]);
			//System.out.println(num[i]);
		}		
		Arrays.sort(num);
		answer = Integer.toString(num[0])+" "+Integer.toString(num[num.length-1]);
		return answer;
	}
}