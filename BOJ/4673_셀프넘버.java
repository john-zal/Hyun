package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		 //Scanner sc = new Scanner(System.in);
		 boolean[] arr = new boolean[10000];
		 for(int i = 0; i<arr.length; i++) {
			 if(s.self(i+1) < 10000+1)
			 arr[s.self(i+1)-1] = true;
		 }
		 for(int i = 0; i<arr.length; i++) {
			 if(arr[i] == false) {
				 System.out.println(i+1);
			 }
		 }		 
	}
}
class Solution{
	public int self(int n) {
		int answer = n; //+125
		while(n>0) {			
			answer += n%10; 
			n /=10;
		}
		return answer;
	}
}