package programmers;


import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {	
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		System.out.println(s.solution(num));
		
	}
}
class Solution {
    public int solution(int num) {
    	if(num == 0)
    	return 1;
    	    	
    	return num * solution(num-1);
    	// solution(int 5) == 5 * solution(4);
    	// solution (int 4) == 4 * solution(3);
    	// solution (int 3) == 3 * solution(2);
    	// solution (int 2) == 2 * solution(1);
    	// solution (int 1) == 1 * solution(0); //탈출
    	//									1 * 1(return) = 1
    	
    	// solution (int 2) == 2 * solution(1);  -> 2
    	// solution (int 3) == 3 * solution(2);  -> 6
    	// solution (int 4) == 4 * solution(3);(6)  -> 24
    	// solution (int 5) == 5 * solution(4);(24)  -> 120
    	// return 120;	
    	// 54321 0 -> 12345 //스택구조
    }
}
