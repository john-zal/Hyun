package programmers;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int[] A = {1,2};
		int[] B = {3,4};
		System.out.println(s.solution(A,B));
	}
}
class Solution
{
    public int solution(int []A, int []B)
    {
    	//가장 작은 수*가장 큰 수+" -> 최소값
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        for(int i = 0; i<A.length; i++) {
        		answer += A[i] * B[(B.length-1)-i];
        }        
        return answer;
    }
}