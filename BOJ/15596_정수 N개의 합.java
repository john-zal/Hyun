package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		// String a = sc.next();
		 
		int[] a = new int[10];
		for(int i= 0; i<a.length; i++) {
			a[i] = sc.nextInt();
		}
		System.out.println(s.sum(a));

	}
}
class Solution {
	public long sum(int[] a) {
			long answer = 0;
			for(int i = 0; i<a.length; i++) {
				answer += (long)a[i];
			}
        	return answer;
    }
}