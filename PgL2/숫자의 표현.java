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
		int answer = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			//System.out.println("i :"+i);
			for (int j = i; j <= n; j++) {				
				sum += j;
				//System.out.println(sum);
				if (sum == n) {
					answer += 1;
					//System.out.println("앤서"+answer);
					sum =0;
					break;
				} else if(sum > n) {
					sum = 0;					
					break;
				}
			}
		}
		return answer;
	}
}