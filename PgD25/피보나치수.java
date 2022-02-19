package programmers;

import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int n = 100000;
		System.out.println(s.solution(n));
	}
}
class Solution {
    public int solution(int n) {
    	int  answer = 0;
    	int  a = 0;
    	int  b = 1;
    	int c = 1234567;
    	
    	for(int i = 2; i<=n; i++) {
    			answer=((a%c)+(b%c))%c;
    			a = b;
    			b = answer;
    	}
        return answer;
    }
}