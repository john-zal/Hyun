package programmers;

import java.util.ArrayList;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);

		String ss = "one4seveneight";
		System.out.println(s.solution(ss));
	}
}

class Solution {
	public int solution(String s) {
		int answer = 0;
		 
		String[] a = {"0","1","2","3","4","5","6","7","8","9"};
		String[] b = {"zero","one","two","three","four","five","six","seven","eight","nine"};
		for(int i = 0; i<a.length; i++) {
			s= s.replace(b[i], a[i]);
		}
		answer = Integer.parseInt(s);
		return answer;
	}
}