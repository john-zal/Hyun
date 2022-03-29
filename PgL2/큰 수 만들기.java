package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String number = "1";
		int k = 0; // 제거할 숫자
		System.out.println(s.solution(number, k));
	}
}

class Solution {
	public String solution(String number, int k) {
		StringBuilder answer = new StringBuilder();
		int max = 0;
		int index = 0;
		for (int i = 0; i <number.length()-k; i++) { // 자릿수 10-4 6
			max = 0;
			for (int j = index; j <= k+i; j++) { 
				if (max < number.charAt(j)-'0') {
					max = number.charAt(j)-'0';
					index = j+1; //3 +1						
				}
			}
			answer.append(max);
		}
		return answer.toString();
	}
}